#include "pipex.h"

void    ft_cleanup(t_pipex *pipex)
{
    int j;
    pipex->i = 0;
    while (pipex->i < (int) pipex->command_count)
    {
        if (pipex->command_paths[pipex->i])
        {
            free(pipex->command_paths[pipex->i]);
            pipex->command_paths[pipex->i] = NULL;
        }
        if (pipex->command_arguments[pipex->i])
        {
            free(pipex->command_arguments[pipex->i]);
            pipex->command_arguments[pipex->i] = NULL;
        }
        j = 0;
        if (pipex->command_tokens[pipex->i])
        {
            while (pipex->command_tokens[pipex->i][j])
            {
                free(pipex->command_tokens[pipex->i][j]);
                pipex->command_tokens[pipex->i][j] = NULL;
                j++;
            }
            free(pipex->command_tokens[pipex->i]);
            pipex->command_tokens[pipex->i] = NULL;
        }
        pipex->i++;
    }
    free(pipex->command_paths);
    pipex->command_paths = NULL;
    free(pipex->command_arguments);
    pipex->command_arguments = NULL;
    free(pipex->command_tokens);
    pipex->command_tokens = NULL;
    free(pipex->pid);
    pipex->pid = NULL;
}
