/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:14:27 by smishos           #+#    #+#             */
/*   Updated: 2024/10/14 15:14:28 by smishos          ###   ########.fr       */
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
