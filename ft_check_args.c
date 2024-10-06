#include "pipex.h"

void ft_check_files(t_pipex *pipex, int argc, char **argv)
{
		pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1 && access(argv[1], F_OK))
		error_exit(pipex, "No such file or directory\n");
	else if (pipex->infile == -1 && !access(argv[1], F_OK))
		error_exit(pipex, "Permission denied\n");
	pipex->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfile == -1 && access(argv[argc - 1], F_OK))
		error_exit(pipex, "No such file or directory\n");
	else if (pipex->outfile == -1 && !access(argv[argc - 1], F_OK))
		error_exit(pipex, "Permission denied\n");
}

// void ft_check_commands(t_pipex *pipex, char **argv)
// {
// 	while (pipex->i < pipex->command_count)
// 	{
// 		pipex->command_arguments[pipex->i] = ft_strdup(argv[2 + pipex->i]);
// 		pipex->i++;
// 	}
// 	pipex->command_arguments[pipex->i] = NULL;
// }

void ft_check_args(t_pipex *pipex, int argc, char **argv)
{
	ft_check_files(pipex, argc, argv);
	// ft_check_commands(pipex, argv);
}
