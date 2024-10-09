/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedapperfoxtrot <thedapperfoxtrot@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:26:10 by thedapperfo       #+#    #+#             */
/*   Updated: 2024/10/09 23:26:42 by thedapperfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_exit(t_pipex *pipex, char *complaint, char *msg, int code)
{
	if (complaint)
	{
		ft_putstr_fd(complaint, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(msg, 2);
	if (pipex->argc == 5)
		ft_cleanup(pipex);
	exit(code);
}
