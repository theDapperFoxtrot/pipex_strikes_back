/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedapperfoxtrot <thedapperfoxtrot@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:16:59 by smishos           #+#    #+#             */
/*   Updated: 2024/10/10 01:35:37 by thedapperfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// This is where we loop through the paths to find the executable
// and store the full path to the executable in the command_arguments array
int	loop_paths(t_pipex *pipex, char *path, char **cmd_tokens)
{
	char	**paths;

	paths = ft_split(path, ':');
	if (!paths)
		error_exit(pipex, NULL, \
			"split failed on splitting up the paths environment variable\n", 1);
	return (validate_path(pipex, paths, cmd_tokens));
}

// This is used when the command given is a full path to the executable
// OR we're given a directory in which there is no valid command,
// we check if it is executable and return 1 if it is,
// else we exit with an error message
int	ft_slash_check(t_pipex *pipex, char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
		{
			if (!access(cmd, F_OK))
			{
				if (!access(cmd, X_OK))
					return (1);
				else
					error_exit(pipex, cmd, "Permission denied\n", 126);
			}
			else
				error_exit(pipex, cmd, "No such file or directory \n", 127);
		}
		i++;
	}
	return (0);
}

void	malloc_abs_path1(t_pipex *pipex, char **cmd_tokens)
{
	int		arg_count;
	int		i;

	arg_count = 0;
	i = 0;
	while (cmd_tokens[arg_count])
		arg_count++;
	pipex->cmd_args1 = (char **)malloc(sizeof(char *) * (arg_count + 1));
	if (!pipex->cmd_args1)
		error_exit(pipex, NULL, "Failed to allocate memory for cmd_args1\n", 1);
	while (i < arg_count)
	{
		pipex->cmd_args1[i] = ft_strdup(cmd_tokens[i]);
		i++;
	}
	pipex->cmd_args1[i] = NULL;
}

void	malloc_abs_path2(t_pipex *pipex, char **cmd_tokens)
{
	int		arg_count;
	int		i;

	arg_count = 0;
	i = 0;
	while (cmd_tokens[arg_count])
		arg_count++;
	pipex->cmd_args2 = (char **)malloc(sizeof(char *) * (arg_count + 1));
	if (!pipex->cmd_args2)
		error_exit(pipex, NULL, "Failed to allocate memory for cmd_args2\n", 1);
	while (i < arg_count)
	{
		pipex->cmd_args2[i] = ft_strdup(cmd_tokens[i]);
		i++;
	}
	pipex->cmd_args2[i] = NULL;
}

// Here is where we check if we were given a directory
// or simply the name of the executable where we then loop
// through the paths to find the executable and
// store the full path to the executable in the command_arguments array
int	ft_parse_commands(t_pipex *pipex, char **envp, \
	char *cmd, char **exec_args)
{
	char	*path;
	char	**cmd_tokens;

	if (cmd)
		cmd_tokens = ft_split(cmd, ' ');
	if (!cmd_tokens)
		error_exit(pipex, NULL, "Failed to split commands into tokens\n", 1);
	if (ft_slash_check(pipex, cmd_tokens[0]))
	{
		if (pipex->i == 0)
			malloc_abs_path1(pipex, cmd_tokens);
		else
			malloc_abs_path2(pipex, cmd_tokens);
		free_split(cmd_tokens);
		return (0);
	}
	path = get_paths(pipex, envp, cmd);
	if (loop_paths(pipex, path, cmd_tokens))
		return (free_path_and_tokens(path, cmd_tokens));
	else
	{
		free_path_and_tokens(path, cmd_tokens);
		free_exec_args_and_exit(pipex, cmd, exec_args);
	}
	return (0);
}
