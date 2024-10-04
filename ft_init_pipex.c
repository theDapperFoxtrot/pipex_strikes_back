#include "pipex.h"

void ft_init_pipex(t_pipex *pipex, int argc)
{
	pipex->argc = argc;
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->command_count = pipex->argc - 3;
	pipex->i = 0;
	pipex->pid = (pid_t *)malloc(sizeof(pid_t) * pipex->command_count);
	if (!pipex->pid)
		error_exit(pipex, "Failed to allocate memory for pid array\n");
	pipex->command_paths = (char **)malloc(sizeof(char *) * pipex->command_count);
	if (!pipex->command_paths)
		error_exit(pipex, "Failed to allocate memory for command_paths\n");
	pipex->command_arguments = (char **)malloc(sizeof(char *) * pipex->command_count);
	if (!pipex->command_arguments)
		error_exit(pipex, "Failed to allocate memory for command_arguments\n");
	pipex->paths = (char **)malloc(sizeof(char *) * pipex->command_count);
	if (!pipex->paths)
		error_exit(pipex, "Failed to allocate memory for paths\n");
}
