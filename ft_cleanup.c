#include "pipex.h"

void    ft_cleanup(t_pipex *pipex)
{
	free_split(pipex->cmd_args1);
	free_split(pipex->cmd_args2);
}

void    free_split(char **split_array)
{
	int i = 0;

	if (split_array != NULL)
	{
		while (split_array[i])
		{
			free(split_array[i]);
			split_array[i] = NULL;
			i++;
		}
		free(split_array);
		split_array = NULL;
	}
}
