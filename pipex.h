/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:15:24 by smishos           #+#    #+#             */
/*   Updated: 2024/10/14 17:55:11 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	int		argc;
	int		infile;
	int		outfile;
	int		i;
	char	**cmd_args1;
	char	**exec_args1;
	char	**cmd_args2;
	char	**exec_args2;
	char	**cmd_tokens;
	int		free_cmd_tokens_flag;
	int		close_infile;
	int		close_outfile;
	int		command_count;
	int		fd[2];
	pid_t	pid[2];
}		t_pipex;

int		main(int argc, char **argv, char **envp);
void	ft_init_pipex(t_pipex *pipex, int argc);
void	execute_loop(t_pipex *pipex, int argc, char **argv, char **envp);
void	ft_parse_commands(t_pipex *pipex, char **envp, char *cmd);
void	cmd_not_found_exit(t_pipex *pipex, char *cmd);
void	no_such_file_and_exit(t_pipex *pipex, char *cmd);
void	perm_denied_and_exit(t_pipex *pipex, char *cmd);
int		free_path_and_tokens(t_pipex *pipex, char *path);
void	malloc_abs_path1(t_pipex *pipex, char **cmd_tokens);
void	malloc_abs_path2(t_pipex *pipex, char **cmd_tokens);
char	*get_paths(t_pipex *pipex, char **envp, char *cmd);
int		loop_paths(t_pipex *pipex, char *path, char **cmd_tokens);
int		ft_slash_check(t_pipex *pipex, char *cmd);
int		validate_path(t_pipex *pipex, char **paths, char **cmd);
int		allocate_cmd_args_arrays(t_pipex *pipex, char **cmd_tokens);
void	allocate_cmd_args(t_pipex *pipex, char *full_path, char **cmd_tokens);
int		access_check(t_pipex *pipex, char *full_path, char **cmd_tokens);
void	free_split(char **split_array);
void	child_process1(t_pipex *pipex, char **argv, char **envp);
void	child_process2(t_pipex *pipex, char **argv, int argc, char **envp);
void	execute_loop(t_pipex *pipex, int argc, char **argv, char **envp);
void	close_fds(t_pipex *pipex);
int		handle_exit(t_pipex *pipex);
int		error_exit(t_pipex *pipex, char *complaint, char *msg, int code);
void	ft_cleanup(t_pipex *pipex);

#endif