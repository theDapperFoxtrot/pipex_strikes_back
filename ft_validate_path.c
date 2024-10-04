#include "pipex.h"

// This function is used to check if the path is valid
static int access_check(char *full_path, t_pipex *pipex)
{
	if (!access(full_path, X_OK))
	{
		char **cmd_tokens;
		int i;

		i = 1;
		cmd_tokens = ft_split(pipex->command_arguments[pipex->i], ' ');
		if (!cmd_tokens)
			error_exit(pipex, "Failed to allocate memory for cmd_tokens in access_check\n");
		while (cmd_tokens[i])
		{
			pipex->paths[i] = ft_strdup(cmd_tokens[i]);
			i++;
		}
		free_split(cmd_tokens);
		pipex->paths[0] = ft_strdup(full_path); // Store the full path to the executable
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
int validate_path(t_pipex *pipex, char **paths, char **cmd)
{
	char *full_path;
	char *temp;
	int i;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			error_exit(pipex, "Malloc failed\n");
		full_path = ft_strjoin(temp, cmd[0]);
		free(temp); // Free the intermediate result
		if (!full_path)
			error_exit(pipex, "Malloc failed\n");
		if (access_check(full_path, pipex) == 1)
		{
			free_split(paths);
			free(full_path);
			return (1); // Path found and stored
		}
		i++;
	}
	free_split(paths);
	return (0); // No valid path found
}
