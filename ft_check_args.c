/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:27:45 by thedapperfo       #+#    #+#             */
/*   Updated: 2024/10/10 15:49:31 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_files(t_pipex *pipex, int argc, char **argv)
{
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->infile == -1 && access(argv[1], F_OK))
		error_exit(pipex, argv[1], "No such file or directory\n", 0);
	else if (pipex->infile == -1 && !access(argv[1], F_OK))
		error_exit(pipex, argv[1], "Permission denied\n", 0);
	if (pipex->outfile == -1 && access(argv[argc - 1], F_OK))
		error_exit(pipex, argv[argc - 1], "No such file or directory\n", 1);
	else if (pipex->outfile == -1 && !access(argv[argc - 1], F_OK))
		error_exit(pipex, argv[argc - 1], "Permission denied\n", 1);
}

void	ft_check_args(t_pipex *pipex, int argc, char **argv)
{
	ft_check_files(pipex, argc, argv);
}
