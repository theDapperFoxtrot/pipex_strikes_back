#include "pipex.h"

int allocate_cmd_args_arrays(t_pipex *pipex, char **cmd_tokens)
{
	int arg_count;

	arg_count = 0;
	if (pipex->i == 0)
	{
		while (cmd_tokens[arg_count])
			arg_count++;
		pipex->cmd_args1 = (char **)malloc(sizeof(char *) * (arg_count + 1));
		if (!pipex->cmd_args1)
			error_exit(pipex,cmd_tokens[0], "Failed to allocate memory for cmd_args1\n", 1);
	}
	if (pipex->i == 1)
	{
		while (cmd_tokens[arg_count])
			arg_count++;
		pipex->cmd_args2 = (char **)malloc(sizeof(char *) * (arg_count + 1));
		if (!pipex->cmd_args2)
			error_exit(pipex, cmd_tokens[0], "Failed to allocate memory for cmd_args2\n", 1);
	}
	return (arg_count);
}

void allocate_cmd_args(t_pipex *pipex, char *full_path, char **cmd_tokens)
{
	int i;
	int arg_count;

	i = 1;
	arg_count = allocate_cmd_args_arrays(pipex, cmd_tokens);
	while (cmd_tokens[i])
	{
		if (pipex->i == 0)
			pipex->cmd_args1[i] = ft_strdup(cmd_tokens[i]);
		else
			pipex->cmd_args2[i] = ft_strdup(cmd_tokens[i]);
		i++;
	}
	if (pipex->i == 0)
	{
		pipex->cmd_args1[0] = ft_strdup(full_path); // Store the full path to the executable
		pipex->cmd_args1[arg_count] = NULL;
	}
	else
	{
		pipex->cmd_args2[0] = ft_strdup(full_path); // Store the full path to the executable
		pipex->cmd_args2[arg_count] = NULL;
	}
}

// This function is used to check if the path is valid
static int access_check(t_pipex *pipex, char *full_path, char **cmd_tokens)
{
	if (!access(full_path, X_OK))
	{
		allocate_cmd_args(pipex, full_path, cmd_tokens);
		free(full_path);
		return (1); // Path found and valid
	}
	else
		free(full_path); // Free full_path to avoid memory leaks if path is invalid
	return (0);
}
// This function is used to validate the path of the command given
// Join paths[i] and "/" first
// Join the result with the command
int validate_path(t_pipex *pipex, char **paths, char **cmd_tokens)
{
	char *full_path;
	char *temp;
	int i;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			error_exit(pipex, NULL, "Malloc failed\n", 1);
		full_path = ft_strjoin(temp, cmd_tokens[0]);
		free(temp); // Free the intermediate result
		if (!full_path)
			error_exit(pipex, NULL, "Malloc failed\n", 1);
		if (access_check(pipex, full_path, cmd_tokens) == 1)
		{
			free_split(paths);
			return (1); // Path found and stored
		}
		i++;
	}
	free_split(paths);
	return (0); // No valid path found
}
