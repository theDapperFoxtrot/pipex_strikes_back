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

void ft_check_commands(t_pipex *pipex, char **argv)
{
	pipex->command_arguments = (char **)malloc(sizeof(char *) * pipex->command_count);
	if (!pipex->command_arguments)
		error_exit(pipex, "Malloc failed\n");
	while (pipex->i < (int) pipex->command_count)
	{
		pipex->command_arguments[pipex->i] = (char *)malloc(sizeof(char) * ft_strlen(argv[2 + pipex->i]) + 1);
		pipex->command_arguments[pipex->i] = argv[2 + pipex->i];
		if (!access(argv[2 + pipex->i], X_OK))
			error_exit(pipex, "Permission denied\n");
		pipex->i++;
	}
}

void ft_check_args(t_pipex *pipex, int argc, char **argv)
{
	ft_check_files(pipex, argc, argv);
	ft_check_commands(pipex, argv);
}
