// main()
// {
// 	ft_init_pipex()
// 	ft_check_args()
// 	ft_parse_cmds()
// 	ft_parse_args()
// 	while (cmds)
// 		ft_exec()
// 	ft_cleanup()
// }

#include "pipex.h"

int main (int argc, char **argv, char **envp)
{
	t_pipex pipex;

    if (argc != 5)
    {
        ft_putstr_fd("Unexpected format used\n", 2);
        ft_putstr_fd("Expected format: ./pipex file1 cmd1 cmd2 file2\n", 2);
        exit (1);
    }
	ft_init_pipex(&pipex, argc);
	pipex.command_count = argc - 3;
	ft_check_args(&pipex, argc, argv);
	pipex.i = 0;
	while (pipex.i < (int) pipex.command_count)
	{
		ft_parse_commands(&pipex, envp, pipex.cmd[pipex.i]);
		pipex.i++;
	}
	ft_parse_args(&pipex, argc, argv, envp);
// while (cmds)
// {
// 	ft_exec();
// }
// void		ft_cleanup();
}
