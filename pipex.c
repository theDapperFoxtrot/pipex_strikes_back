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
		ft_parse_commands(&pipex, envp, pipex.command_arguments[pipex.i]);
		pipex.i++;
	}

	pipex.i = 0;
	if (pipe(pipex.fd) == -1)
		error_exit(&pipex, "Pipe function failed\n");

	while (pipex.i < pipex.command_count)
	{
		pipex.pid = (pid_t) fork();
		if (pipex.pid < 0)
			error_exit(&pipex, "Fork was unsuccessful");
		if (pipex.pid == 0 && pipex.i == 0)
		{
			close(pipex.fd[0]);
			// printf("Hello, I am child processs #%d\n", pipex.i + 1);
			dup2(pipex.infile, STDIN_FILENO);
			dup2(pipex.fd[1], STDOUT_FILENO);
			close(pipex.fd[1]);
			execve(pipex.cmd_args1[0], pipex.cmd_args1, envp);
			error_exit(&pipex, "Execve failed for cmd1\n");
		}
		if (pipex.pid == 0 && pipex.i == 1)
		{
			close(pipex.fd[1]);
			// printf("Hello, I am child processs #%d\n", pipex.i + 1);
			dup2(pipex.fd[0], STDIN_FILENO);
			dup2(pipex.outfile, STDOUT_FILENO);
			close(pipex.fd[0]);
			execve(pipex.cmd_args2[0], pipex.cmd_args2, envp);
			error_exit(&pipex, "Execve failed for cmd2\n");
		}
		pipex.i++;
	}
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	wait(NULL);
	wait(NULL);
	error_exit(&pipex, "<<<pipex successful>>>\n");
	// 	ft_exec1();
	// 	ft_exec2();


	// ----------------TESTING---------------------
	// int i = 0;
	// while (pipex.cmd_args1[i])
	// {
	// 	printf("%s \n", pipex.cmd_args1[i]);
	// 	i++;
	// }
	// i = 0;
	// while (pipex.cmd_args2[i])
	// {
	// 	printf("%s \n", pipex.cmd_args2[i]);
	// 	i++;
	// }
// At this point I would like to loop through all the arrays in my struct to determine that the data is populated and null-terminated
// void		ft_cleanup();
}


// main()
// {
// 	ft_init_pipex()
// 	ft_check_args()
// 	ft_parse_cmds()
// 	ft_parse_args()
// 	while (cmds)
// 		ft_exec()
// 	ft_cleanup()
// }