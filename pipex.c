#include "pipex.h"

int main (int argc, char **argv, char **envp)
{
	t_pipex pipex;

	ft_init_pipex(&pipex, argc);
    if (argc != 5)
    {
        ft_putstr_fd("Unexpected format used\n", 2);
        error_exit(&pipex, "Expected format: ./&pipex file1 cmd1 cmd2 file2\n");
    }
	ft_check_args(&pipex, argc, argv);
	pipex.i = 0;
	while (pipex.i < pipex.command_count)
	{
		ft_parse_commands(&pipex, envp, pipex.command_arguments[pipex.i]);
		printf("%s", pipex.command_arguments[pipex.i]);
		pipex.i++;
	}
	pipex.i = 0;
	printf("%d\n", pipex.argc);
	error_exit(&pipex, "Test\n");
// At this point I would like to loop through all the arrays in my struct to determine that the data is populated and null-terminated
// ft_parse_args(&pipex, argc, argv, envp);
// while (cmds)
// {
// 	ft_exec();
// }
// void		ft_cleanup();
}
