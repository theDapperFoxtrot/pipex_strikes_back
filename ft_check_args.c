#include "pipex.h"

void ft_check_files(t_pipex *pipex, int argc, char **argv)
{
		pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1 && access(argv[1], F_OK))
		printf("No such file or directory\n");
	else if (pipex->infile == -1 && !access(argv[1], F_OK))
		printf("Permission denied\n");
	pipex->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfile == -1 && access(argv[argc - 1], F_OK))
		printf("No such file or directory\n");
	else if (pipex->outfile == -1 && !access(argv[argc - 1], F_OK))
		printf("Permission denied\n");
}

void ft_check_commands(t_pipex *pipex, char **argv)
{
	pipex->cmd = (char **)malloc(sizeof(char *) * pipex->command_count);
	if (!pipex->cmd)
		printf("Malloc failed\n");
	while (pipex->i < (int) pipex->command_count)
	{
		pipex->cmd[pipex->i] = argv[2 + pipex->i];
		if (!access(argv[2 + pipex->i], X_OK))
			printf("Permission denied\n");
		pipex->i++;
	}
}

void ft_check_args(t_pipex *pipex, int argc, char **argv)
{
	ft_check_files(pipex, argc, argv);
	ft_check_commands(pipex, argv);
}
