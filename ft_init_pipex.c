#include "pipex.h"

void ft_init_pipex(t_pipex *pipex, int argc)
{
	pipex->argc = argc;
	pipex->command_count = pipex->argc - 3;
	pipex->i = 0;
	// pipex->pid = (pid_t)malloc(sizeof(int) * pipex->command_count);
	// if (!pipex->pid)
	// 	error_exit(pipex, "Failed to allocate memory for pid array\n");
	pipex->command_arguments = (char **)malloc(sizeof(char *) * (pipex->command_count + 1));
	if (!pipex->command_arguments)
		error_exit(pipex, "Failed to allocate memory for command_arguments\n");
}
