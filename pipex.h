#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	int		argc;
	int		infile;
	int		outfile;
	int     i; //track which command we're working with (first/second)
	char	**cmd_args1;
	char	**cmd_args2;
	int  	command_count;
	int		fd[2];
	pid_t   pid[2];
} t_pipex;

int		main(int argc, char **argv, char **envp);
void	ft_init_pipex(t_pipex *pipex, int argc);
void	ft_check_args(t_pipex *pipex, int argc, char **argv);
void	execute_loop(t_pipex *pipex, int argc, char **argv, char **envp);
int		ft_parse_commands(t_pipex *pipex, char **envp, char *cmd, char **exec_args);
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
int		error_exit(t_pipex *pipex,char *complaint, char *msg, int code);
void	ft_cleanup(t_pipex *pipex);

#endif