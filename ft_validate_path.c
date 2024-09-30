#include "pipex.h"

static int allocate_command_path(t_pipex *pipex)
{
    if (!pipex->command_paths)
    {
        pipex->command_paths = (char **)malloc(sizeof(char *) * pipex->command_count);
        if (!pipex->command_paths) {
            printf("Malloc failed for command_paths\n");
            return (0);
        }
    }
    return (1);
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
int validate_path(t_pipex *pipex, char **paths, char *command_name)
{
    char *tmp;
    int i;

    i = 0;
    while (paths[i])
    {
        tmp = (char *)malloc(sizeof(char) * (ft_strlen(paths[i]) + ft_strlen(command_name) + 2)); // command_name, not cmd
        if (!tmp)
		{
            printf("Malloc failed\n");
            return (0); // Return 0 on failure to indicate command not found
        }
        tmp = ft_strjoin(paths[i], "/");
        tmp = ft_strjoin(tmp, command_name);
        allocate_command_path(pipex);
        if (access_check(tmp, pipex) == 1)
            return (1);
        i++;
    }
    return (0); // No valid path found
}
