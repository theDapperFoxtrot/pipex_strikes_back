#include "pipex.h"

int main (int argc, char **argv, char **envp)
{
	t_pipex pipex;

	ft_init_pipex(&pipex, argc);
    if (argc != 5)
    {
        ft_putstr_fd("Unexpected format used\n", 2);
        error_exit(&pipex, NULL, "Expected format: ./&pipex file1 cmd1 cmd2 file2\n", 1);
    }
	ft_check_args(&pipex, argc, argv);
	pipex.i = 0;
	while (pipex.i < pipex.command_count)
	{
		ft_parse_commands(&pipex, envp, argv[2 + pipex.i]);
		pipex.i++;
	}

	pipex.i = 0;
	if (pipe(pipex.fd) == -1)
		error_exit(&pipex, NULL, "Pipe function failed\n", 1);

	while (pipex.i < pipex.command_count)
	{
		pipex.pid[pipex.i] = (pid_t) fork();
		if (pipex.pid[pipex.i] < 0)
			error_exit(&pipex, NULL, "Fork was unsuccessful", 1);
		if (pipex.pid[pipex.i] == 0 && pipex.i == 0)
		{
			if (argv[2] == NULL || argv[2][0] == ' ')
				error_exit(&pipex, argv[2], "command not found\n", 0);
			close(pipex.fd[0]);
			close(pipex.outfile);
			dup2(pipex.infile, STDIN_FILENO);
			close(pipex.infile);
			dup2(pipex.fd[1], STDOUT_FILENO);
			close(pipex.fd[1]);
			execve(pipex.cmd_args1[0], pipex.cmd_args1, envp);
			error_exit(&pipex, argv[2], "Is a directory\n", 0);
		}
		if (pipex.pid[pipex.i] == 0 && pipex.i == 1)
		{
			if (argv[argc - 1] == NULL || argv[argc - 1][0] == ' ')
				error_exit(&pipex, argv[argc - 1], "command not found\n", 0);
			close(pipex.fd[1]);
			close(pipex.infile);
			dup2(pipex.fd[0], STDIN_FILENO);
			dup2(pipex.outfile, STDOUT_FILENO);
			close(pipex.outfile);
			close(pipex.fd[0]);
			execve(pipex.cmd_args2[0], pipex.cmd_args2, envp);
			error_exit(&pipex, argv[argc -1], "Is a directory\n", 126);
		}
		pipex.i++;
	}
	close(pipex.infile);
	close(pipex.outfile);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	pipex.i = 0;
	int status;
	int exit_code;
	int child_pid;

	while (pipex.i < 2)
	{
		child_pid = waitpid(-1, &status, 0);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			status = WTERMSIG(status) + 128;
		if (child_pid == pipex.pid[1])
			exit_code = status;
		pipex.i++;
	}
	ft_cleanup(&pipex);
	return (exit_code);
}

// WIFEXITED
// WEXITSTATUS
// WIFSIGNALED