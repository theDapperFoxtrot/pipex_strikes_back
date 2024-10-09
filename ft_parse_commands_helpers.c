/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_commands_helpers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedapperfoxtrot <thedapperfoxtrot@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:20:02 by thedapperfo       #+#    #+#             */
/*   Updated: 2024/10/10 01:35:22 by thedapperfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// This function is to locate the PATH variable in the
// environment variables and return the value of the PATH variable
char	*get_paths(t_pipex *pipex, char **envp, char *cmd)
{
	static char	*path;
	int			i;

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
	if (!path && access(cmd, X_OK))
		error_exit(pipex, cmd, "No such file or directory\n", 127);
	return (path);
}

void	free_exec_args_and_exit(t_pipex *pipex, char *cmd, char **exec_args)
{
	free_split(exec_args);
	if (pipex->i == 0)
		error_exit(pipex, cmd, "command not found\n", 1);
	else
		error_exit(pipex, cmd, "command not found\n", 127);
}

int	free_path_and_tokens(char *path, char **cmd_tokens)
{
	free(path);
	free_split(cmd_tokens);
	return (0);
}
