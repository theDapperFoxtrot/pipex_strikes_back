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
static char *first_word(char *str)
{
	int i;
	char *word;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	word = (char *)malloc(sizeof(char) * i + 1);
	if (!word)
		printf("Malloc failed\n");
	i = 0;
	while (str[i] && str[i] != ' ')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void loop_paths(t_pipex *pipex, char *path, char *cmd)
{
	char **paths;
	char *command_name;
	int i;

	i = 0;
	paths = ft_split(path, ':');
	if (!paths[i])
		printf("PATH is empty\n");
	command_name = first_word(cmd);
	if (validate_path(pipex, paths, command_name))
	{
		// printf("Command found: %s\n", pipex->command_paths[pipex->i]);
		free(command_name);
		return ;
	}
	else
	{
		printf("Command not found\n");
		exit(1); //<-this should change depending whether this is first command or not
	}
}

void ft_parse_commands(t_pipex *pipex, char **envp, char *cmd)
{
	char 	*path;
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
		{
			pipex->command_paths[pipex->i] = first_word(cmd);
			if (!access(pipex->command_paths[pipex->i], X_OK))
			{
				malloc_and_add_command_path(pipex);
				return ;
			}
			else
			{
				printf("Directory/invalid command");
				exit(1);
			}
		}
		i++;
	}
	path = get_paths(envp);
	loop_paths(pipex, path, cmd);
	free(path);
}
