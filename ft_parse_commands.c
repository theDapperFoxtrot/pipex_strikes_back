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
		printf("PATH is empty\n");
	if (validate_path(pipex, paths, cmd))
		return ;
	else
	{
		printf("Command not found\n");
		exit(1); //<-this should change depending whether this is first command or not
	}
}

int ft_slash_check(char *cmd, t_pipex *pipex)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
		{
			pipex->command_paths[pipex->i] = first_word(cmd);
			if (!access(pipex->command_paths[pipex->i], X_OK))
				return ;
			else
			{
				printf("Directory/invalid command");
				exit(1);
			}
		}
		i++;
	}
}

void ft_parse_commands(t_pipex *pipex, char **envp, char *cmd)
{
	char 	*path;
	char	**tokens;

	tokens = ft_split(cmd, ' ');
	printf("%s %s\n", tokens[0], tokens[1]);
	if (ft_slash_check(cmd, pipex))
		return ;
	path = get_paths(envp);
	loop_paths(pipex, path, tokens[0]);
	free(path);
}
