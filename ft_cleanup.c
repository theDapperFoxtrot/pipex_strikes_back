#include "pipex.h"

void    ft_cleanup(t_pipex *pipex)
{
	pipex->i = 0;
	while (pipex->i < (int) pipex->command_count)
	{
		if (pipex->command_arguments[pipex->i])
			free(pipex->command_arguments[pipex->i]);
		pipex->i++;
	}
	pipex->i = 0;
	while (pipex->i < (int) pipex->command_count)
	{
		if (pipex->command_paths[pipex->i])
			free(pipex->command_paths[pipex->i]);
		pipex->i++;
	}
	free(pipex->command_arguments);
	free(pipex->command_paths);
	free(pipex->pid);
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
