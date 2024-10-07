#include "pipex.h"

int error_exit(t_pipex *pipex, char *complaint, char *msg, int code)
{
    if (complaint)
    {
        ft_putstr_fd(complaint, 2);
        ft_putstr_fd(": ", 2);
    }
    ft_putstr_fd(msg, 2);
    if (pipex->argc == 5)
        ft_cleanup(pipex);
    exit(code);
}
