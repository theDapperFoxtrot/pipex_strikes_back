#include "pipex.h"

void ft_init_pipex(t_pipex *pipex, int argc)
{
	ft_bzero(pipex, sizeof(t_pipex));
	pipex->command_count = argc - 3;
	pipex->pid = (pid_t *)malloc(sizeof(pid_t) * pipex->command_count);

}
