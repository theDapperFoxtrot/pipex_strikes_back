/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:33:57 by smishos           #+#    #+#             */
/*   Updated: 2024/10/09 19:07:11 by smishos          ###   ########.fr       */
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
	ft_check_args(&pipex, argc, argv);
	pipex.i = 0;
	if (pipe(pipex.fd) == -1)
		error_exit(&pipex, NULL, "Pipe function failed\n", 1);
	execute_loop(&pipex, argc, argv, envp);
	close_fds(&pipex);
	pipex.i = 0;
	exit_code = handle_exit(&pipex);
	ft_cleanup(&pipex);
	return (exit_code);
}
