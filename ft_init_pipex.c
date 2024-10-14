/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:14:42 by smishos           #+#    #+#             */
/*   Updated: 2024/10/14 17:56:01 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_pipex(t_pipex *pipex, int argc)
{
	pipex->argc = argc;
	pipex->command_count = pipex->argc - 3;
	pipex->i = 0;
	pipex->cmd_args1 = NULL;
	pipex->cmd_args2 = NULL;
	pipex->exec_args1 = NULL;
	pipex->exec_args2 = NULL;
	pipex->cmd_tokens = NULL;
	pipex->free_cmd_tokens_flag = 0;
	pipex->close_infile = 0;
	pipex->close_outfile = 0;
}
