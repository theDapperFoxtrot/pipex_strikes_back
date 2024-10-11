/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:27:35 by thedapperfo       #+#    #+#             */
/*   Updated: 2024/10/11 14:20:35 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cleanup(t_pipex *pipex)
{
	free_split(pipex->cmd_args1);
	free_split(pipex->cmd_args2);
	free_split(pipex->exec_args1);
	free_split(pipex->exec_args2);
	if (pipex->free_cmd_tokens_flag == 1)
		free_split(pipex->cmd_tokens);
}

void	free_split(char **split_array)
{
	int	i;

	i = 0;
	if (split_array != NULL)
	{
		while (split_array[i] != NULL)
		{
			free(split_array[i]);
			split_array[i] = NULL;
			i++;
		}
		free(split_array);
		split_array = NULL;
	}
}
