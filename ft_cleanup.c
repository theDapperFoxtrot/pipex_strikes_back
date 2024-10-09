/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedapperfoxtrot <thedapperfoxtrot@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:27:35 by thedapperfo       #+#    #+#             */
/*   Updated: 2024/10/09 23:27:36 by thedapperfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cleanup(t_pipex *pipex)
{
	free_split(pipex->cmd_args1);
	free_split(pipex->cmd_args2);
}

void	free_split(char **split_array)
{
	int	i;

	i = 0;
	if (split_array != NULL)
	{
		while (split_array[i])
		{
			free(split_array[i]);
			split_array[i] = NULL;
			i++;
		}
		free(split_array);
		split_array = NULL;
	}
}
