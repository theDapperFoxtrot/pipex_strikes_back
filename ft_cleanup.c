#include "pipex.h"

void    ft_cleanup(t_pipex *pipex)
{
	pipex->i = 0;
	while (pipex->i < (int) pipex->command_count)
	{
		// if (pipex->command_arguments[pipex->i])
		// 	free(pipex->command_arguments[pipex->i]);
		if (pipex->cmd_args1[pipex->i])
			free(pipex->cmd_args1[pipex->i]);
		if (pipex->cmd_args2[pipex->i])
			free(pipex->cmd_args2[pipex->i]);
		pipex->i++;
	}
	// if (pipex->command_arguments)
	// 	free(pipex->command_arguments);
	if (pipex->cmd_args1)
		free(pipex->cmd_args1);
	if (pipex->cmd_args2)
		free(pipex->cmd_args2);
}

void    free_split(char **split_array)
{
	int i = 0;
	while (split_array[i])
	{
		free(split_array[i]);
		i++;
	}
	free(split_array);
}
