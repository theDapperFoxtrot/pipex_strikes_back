#include "pipex.h"

void ft_init_pipex(t_pipex *pipex, int argc)
{
	pipex->argc = argc;
	pipex->command_count = pipex->argc - 3;
	pipex->i = 0;
	pipex->cmd_args1 = NULL;
	pipex->cmd_args2 = NULL;
}
