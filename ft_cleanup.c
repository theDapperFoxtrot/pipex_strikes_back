/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:14:14 by smishos           #+#    #+#             */
/*   Updated: 2024/10/17 12:31:50 by smishos          ###   ########.fr       */
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
	if (pipex->close_infile == 1)
		if (pipex->infile != -1)
			close(pipex->infile);
	if (pipex->close_outfile == 1)
		if (pipex->outfile != -1)
			close(pipex->outfile);
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
