#include "pipex.h"

static void allocate_command_path(t_pipex *pipex)
{
    if (!pipex->command_paths[pipex->i])
    {
        pipex->command_paths[pipex->i] = (char *)malloc(sizeof(char) * sizeof(pipex->command_arguments[pipex->i]));
        if (!pipex->command_paths[pipex->i])
            error_exit(pipex, "Malloc failed for command_path of \n");
    }
}
static int access_check(char *tmp, t_pipex *pipex)
{
    if (!access(tmp, X_OK))
    {
        pipex->command_paths[pipex->i] = ft_strdup(tmp); // Store the full path to the executable
        free(tmp); // Free the tmp variable as it's no longer needed
        return (1); // Path found and valid
    }
    else
        free(tmp); // Free tmp to avoid memory leaks if path is invalid
    return (0);
}
int validate_path(t_pipex *pipex, char **paths, char *cmd)
{
    char *tmp;
    int i;

    i = 0;
    while (paths[i])
    {
        tmp = (char *)malloc(sizeof(char) * (ft_strlen(paths[i]) + ft_strlen(cmd) + 2)); // command_name, not cmd
        if (!tmp)
            error_exit(pipex, "Malloc failed\n");
        tmp = ft_strjoin(paths[i], "/");
        tmp = ft_strjoin(tmp, cmd);
        allocate_command_path(pipex);
        if (access_check(tmp, pipex) == 1)
            return (1);
        i++;
    }
    return (0); // No valid path found
}
