#include "pipex.h"

// This function is to locate the PATH variable in the environment variables and return the value of the PATH variable
static char *get_paths(char **envp)
{
	char 	*path;
	int 	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(envp[i] + 5);
			break ;
		}
		i++;
	}
	return (path);
}
// This is where we loop through the paths to find the executable and store the full path to the executable in the command_arguments array
static int loop_paths(t_pipex *pipex, char *path, char **cmd)
{
	char **paths;

	paths = ft_split(path, ':');
	if (!paths)
		error_exit(pipex, "PATH is empty\n");
	return (validate_path(pipex, paths, cmd));
}
// This is used when the command given is a full path to the executable OR we're given a directory in which there is no valid command, we check if it is executable and return 1 if it is, else we exit with an error message
int ft_slash_check(char *cmd, t_pipex *pipex)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
		{
			if (!access(cmd, X_OK))
				return (1);
			else
				error_exit(pipex, "Directory/invalid command");
		}
		i++;
	}
	return (0);
}

// Here is where we check if we were given a directory or simply the name of the executable where we then loop through the paths to find the executable and store the full path to the executable in the command_arguments array
void ft_parse_commands(t_pipex *pipex, char **envp, char *cmd)
{
	char 	*path;
	char	**cmd_tokens;

	cmd_tokens = ft_split(cmd, ' ');
	if (ft_slash_check(cmd_tokens[0], pipex))
	{
		// pipex->command_paths[pipex->i] = pipex->command_arguments[pipex->i];
		free_split(cmd_tokens);
		return ;
	}
	path = get_paths(envp);
	if (loop_paths(pipex, path, cmd_tokens))
	{
		free(path);
		free_split(cmd_tokens);
		return ;
	}
	else
	{
		free(path);
		free_split(cmd_tokens);
		error_exit(pipex, "Command not found\n");
	}
}
