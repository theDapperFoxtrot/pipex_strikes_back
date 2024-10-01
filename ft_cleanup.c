#include "pipex.h"

void    ft_cleanup(t_pipex *pipex)
{
    int j;
        pipex->i = 0;
        while (pipex->i < (int) pipex->command_count)
        {
            free(pipex->command_paths[pipex->i]);
            free(pipex->command_arguments[pipex->i]);
            j = 0;
            if (pipex->command_tokens[pipex->i])
            {
                while (pipex->command_tokens[pipex->i][j])
                {
                    free(pipex->command_tokens[pipex->i][j]);
                    j++;
                }
                free(pipex->command_tokens[pipex->i]);
            }
            pipex->i++;
        }
        free(pipex->command_paths);
        free(pipex->command_arguments);
        free(pipex->command_tokens);
        free(pipex->pid);
}
