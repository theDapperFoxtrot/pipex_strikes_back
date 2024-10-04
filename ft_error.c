#include "pipex.h"

int error_exit(t_pipex *pipex, char *msg)
{
    ft_putstr_fd(msg, 2);
    if (pipex->argc == 5)
    {
        ft_cleanup(pipex);
    }
    exit(1);
}
