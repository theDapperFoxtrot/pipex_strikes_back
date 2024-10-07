#include "pipex.h"

int main (int argc, char **argv, char **envp)
{
	t_pipex pipex;

	ft_init_pipex(&pipex, argc);
    if (argc != 5)
    {
        ft_putstr_fd("Unexpected format used\n", 2);
        error_exit(&pipex, "Expected format: ./&pipex file1 cmd1 cmd2 file2\n");
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
		error_exit(&pipex, "Pipe function failed\n");

	while (pipex.i < pipex.command_count)
	{
		pipex.pid[pipex.i] = (pid_t) fork();
		if (pipex.pid[pipex.i] < 0)
			error_exit(&pipex, "Fork was unsuccessful");
		if (pipex.pid[pipex.i] == 0 && pipex.i == 0)
		{
			close(pipex.fd[0]);
			close(pipex.outfile);
			printf("Hello, I am child processs #%d\n", pipex.i + 1);
			dup2(pipex.infile, STDIN_FILENO);
			close(pipex.infile);
			dup2(pipex.fd[1], STDOUT_FILENO);
			close(pipex.fd[1]);
			execve(pipex.cmd_args1[0], pipex.cmd_args1, envp);
			error_exit(&pipex, "Is a directory\n");
		}
		if (pipex.pid[pipex.i] == 0 && pipex.i == 1)
		{
			close(pipex.fd[1]);
			close(pipex.infile);
			printf("Hello, I am child processs #%d\n", pipex.i + 1);
			dup2(pipex.fd[0], STDIN_FILENO);
			dup2(pipex.outfile, STDOUT_FILENO);
			close(pipex.outfile);
			close(pipex.fd[0]);
			execve(pipex.cmd_args2[0], pipex.cmd_args2, envp);
			error_exit(&pipex, "Is a directory\n");
		}
		pipex.i++;
	}
	close(pipex.infile);
	close(pipex.outfile);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	pipex.i = 0;
	int status;

	while (waitpid(pipex.pid[pipex.i], &status, 0) > 0)
	{
		pipex.i++;
	}
	printf("%d\n", status);
	ft_cleanup(&pipex);
	return (status);
}
