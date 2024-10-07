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

void		ft_init_pipex(t_pipex *pipex, int argc);
void        ft_check_args(t_pipex *pipex, int argc, char **argv);
void		ft_parse_commands(t_pipex *pipex, char **envp, char *cmd);
int			validate_path(t_pipex *pipex, char **paths, char **cmd);
int			error_exit(t_pipex *pipex, char *msg);
void		ft_cleanup(t_pipex *pipex);
void		free_split(char **split_array);

#endif