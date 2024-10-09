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
void	ft_parse_commands(t_pipex *pipex, char **envp, char *cmd);
int		validate_path(t_pipex *pipex, char **paths, char **cmd);
int		error_exit(t_pipex *pipex,char *complaint, char *msg, int code);
void	ft_cleanup(t_pipex *pipex);
void	free_split(char **split_array);
void	child_process1(t_pipex *pipex, char **argv, char **envp);
void	child_process2(t_pipex *pipex, char **argv, int argc, char **envp);
void	execute_loop(t_pipex *pipex, int argc, char **argv, char **envp);
void	close_fds(t_pipex *pipex);
int		handle_exit(t_pipex *pipex);
void	malloc_abs_path1(t_pipex *pipex, char **cmd_tokens);
void	malloc_abs_path2(t_pipex *pipex, char **cmd_tokens);

#endif