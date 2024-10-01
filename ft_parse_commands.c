#include "pipex.h"

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

static void loop_paths(t_pipex *pipex, char *path, char *cmd)
{
	char **paths;
	int i;

	i = 0;
	paths = ft_split(path, ':');
	if (!paths[i])
		error_exit(pipex, "PATH is empty\n");
	if (validate_path(pipex, paths, cmd))
		return ;
	else
		error_exit(pipex, "Command not found\n");
}

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

void ft_parse_commands(t_pipex *pipex, char **envp, char *cmd)
{
	char 	*path;

	pipex->command_tokens = (char ***)malloc(sizeof(char **) * sizeof(pipex->command_tokens[pipex->i]));
	pipex->command_tokens[pipex->i] = ft_split(cmd, ' ');
	if (ft_slash_check(pipex->command_tokens[pipex->i][0], pipex))
		return ;
	path = get_paths(envp);
	loop_paths(pipex, path, pipex->command_tokens[pipex->i][0]);
	free(path);
}
