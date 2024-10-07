#include "pipex.h"

void ft_check_files(t_pipex *pipex, int argc, char **argv)
{
		pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1 && access(argv[1], F_OK))
		error_exit(pipex, argv[1], "No such file or directory\n", 0);
	else if (pipex->infile == -1 && !access(argv[1], F_OK))
		error_exit(pipex, argv[1], "Permission denied\n", 0);
	pipex->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfile == -1 && access(argv[argc - 1], F_OK))
		error_exit(pipex, argv[argc - 1], "No such file or directory\n", 1);
	else if (pipex->outfile == -1 && !access(argv[argc - 1], F_OK))
		error_exit(pipex, argv[argc - 1], "Permission denied\n", 1);
}

void ft_check_args(t_pipex *pipex, int argc, char **argv)
{
	ft_check_files(pipex, argc, argv);
}
