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
	int    infile;
	int    outfile;
	char    *file1;
	char    *file2;
	char    **cmd;
	char    **cmd_path;
	int     i; //track the current process (from 0)
	char    **command_paths;
	char    ***command_arguments;
	size_t  command_count;
	pid_t   *pid;

} t_pipex;

void		ft_init_pipex(t_pipex *pipex, int argc);
void        ft_check_args(t_pipex *pipex, int argc, char **argv);
void		ft_parse_commands(t_pipex *pipex, char **envp, char *cmd);
void		ft_parse_args(t_pipex *pipex, int argc, char **argv, char **envp);
int			validate_path(t_pipex *pipex, char **paths, char *command_name);

#endif