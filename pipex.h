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
	int     i; //track the current process (from 0)
	char    **command_arguments;
	char 	**command_paths;
	size_t  command_count;
	pid_t   *pid;
} t_pipex;

void		ft_init_pipex(t_pipex *pipex, int argc);
void        ft_check_args(t_pipex *pipex, int argc, char **argv);
void		ft_parse_commands(t_pipex *pipex, char **envp, char *cmd);
int			validate_path(t_pipex *pipex, char **paths, char *command_name);
int			error_exit(t_pipex *pipex, char *msg);
void		ft_cleanup(t_pipex *pipex);
void		free_split(char **split_array);

#endif