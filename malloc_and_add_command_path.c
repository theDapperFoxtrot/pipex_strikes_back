#include "pipex.h"

void malloc_and_add_command_path(t_pipex *pipex)
{
    free(pipex->command_paths[pipex->i]);
    pipex->command_paths[pipex->i] = malloc();
}