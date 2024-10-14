/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:15:08 by smishos           #+#    #+#             */
/*   Updated: 2024/10/14 15:15:09 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex		pipex;
	static int	exit_code;

	ft_init_pipex(&pipex, argc);
	if (argc != 5)
		error_exit(&pipex, NULL, \
			"Expected format: ./&pipex file1 cmd1 cmd2 file2\n", 1);
	if (pipe(pipex.fd) == -1)
		error_exit(&pipex, NULL, "Pipe function failed\n", 1);
	execute_loop(&pipex, argc, argv, envp);
	close_fds(&pipex);
	pipex.i = 0;
	exit_code = handle_exit(&pipex);
	return (exit_code);
}
