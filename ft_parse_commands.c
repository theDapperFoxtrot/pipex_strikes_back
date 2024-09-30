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
static int validate_path(t_pipex *pipex, char **paths, char *command_name, char *cmd)
{
	char *tmp;
	int i;

	i = 0;
		while (paths[i])
	{
		tmp = (char *)malloc(sizeof(char) * (ft_strlen(paths[i]) + ft_strlen(cmd) + 2));
		if (!tmp)
			printf("Malloc failed\n");
		tmp = ft_strjoin(paths[i], "/");
		pipex->cmd_path = (char **)malloc(sizeof(char *) * pipex->command_count);
		if (!pipex->cmd_path)
			printf("Malloc failed\n");
		pipex->cmd_path[pipex->i] = ft_strjoin(tmp, command_name); //without flag
		if (!access(pipex->cmd_path[pipex->i], X_OK))
		{
			pipex->cmd_path[pipex->i] = ft_strjoin(tmp, cmd); //with flag
			return (1);
		}
		i++;
	}
	return (0);
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
	if (validate_path(pipex, paths, command_name, cmd))
	{
		printf("Command found: %s\n", pipex->cmd_path[pipex->i]);
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
	char *path;
	path = get_paths(envp);
	// printf("path: %s\n", path);
	loop_paths(pipex, path, cmd);
	// Some logic to assign cmd_path[pipex->i] to the correct path
	free(path);
}
