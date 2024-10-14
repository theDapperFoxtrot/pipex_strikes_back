/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:14:56 by smishos           #+#    #+#             */
/*   Updated: 2024/10/14 15:14:57 by smishos          ###   ########.fr       */
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
					perm_denied_and_exit(pipex, cmd);
			}
			else
				no_such_file_and_exit(pipex, cmd);
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
void	ft_parse_commands(t_pipex *pipex, char **envp, char *cmd)
{
	char	*path;

	if (cmd)
		pipex->cmd_tokens = ft_split(cmd, ' ');
	if (!pipex->cmd_tokens)
		error_exit(pipex, NULL, "Failed to split commands into tokens\n", 1);
	if (ft_slash_check(pipex, pipex->cmd_tokens[0]))
	{
		if (pipex->i == 0)
			malloc_abs_path1(pipex, pipex->cmd_tokens);
		else
			malloc_abs_path2(pipex, pipex->cmd_tokens);
		free_split(pipex->cmd_tokens);
		return ;
	}
	path = get_paths(pipex, envp, cmd);
	if (loop_paths(pipex, path, pipex->cmd_tokens))
		free_path_and_tokens(pipex, path);
	else
	{
		free_path_and_tokens(pipex, path);
		cmd_not_found_exit(pipex, cmd);
	}
}
