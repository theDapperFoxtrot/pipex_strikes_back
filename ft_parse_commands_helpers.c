/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_commands_helpers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:20:02 by thedapperfo       #+#    #+#             */
/*   Updated: 2024/10/12 17:47:53 by smishos          ###   ########.fr       */
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

void	cmd_not_found_exit(t_pipex *pipex, char *cmd)
{
	if (pipex->i == 0)
		error_exit(pipex, cmd, "command not found\n", 1);
	else
		error_exit(pipex, cmd, "command not found\n", 127);
}

void	no_such_file_and_exit(t_pipex *pipex, char *cmd)
{
	pipex->free_cmd_tokens_flag = 1;
	error_exit(pipex, cmd, "No such file or directory \n", 127);
}

void	perm_denied_and_exit(t_pipex *pipex, char *cmd)
{
	pipex->free_cmd_tokens_flag = 1;
	error_exit(pipex, cmd, "Permission denied\n", 126);
}

int	free_path_and_tokens(t_pipex *pipex, char *path)
{
	pipex->free_cmd_tokens_flag = 1;
	free(path);
	return (0);
}
