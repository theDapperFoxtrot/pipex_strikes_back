#include "pipex.h"

void ft_parse_args(t_pipex *pipex, int argc, char **argv, char **envp) {
    int i;
    (void)envp;
    (void)argc;
    (void)argv;

    pipex->i = 0; // Index for commands
    pipex->command_arguments = (char ***)malloc(sizeof(char **) * pipex->command_count);
    if (!pipex->command_arguments) {
        printf("Malloc failed\n");
        return; // Early exit if malloc fails
    }

    while (pipex->i < (int)pipex->command_count)
	{
        // Initialize the argument array for the current command.
        pipex->command_arguments[pipex->i] = (char **)malloc(sizeof(char *) * (pipex->command_count + 1)); // +1 for NULL
        if (!pipex->command_arguments[pipex->i])
		{
            printf("Malloc failed for command_arguments[%d]\n", pipex->i); // Print error message
            return; // Handle malloc failure
        }
        i = 0; // Reset i for splitting arguments
        // Call ft_split and store the result
        pipex->command_arguments[pipex->i][i] = ft_split(pipex->command_paths[pipex->i], ' ');
        // Verify if ft_split worked and print the output
        if (pipex->command_arguments[pipex->i])
		{
            while (pipex->command_arguments[pipex->i][i] != NULL) {
                printf("Command argument: %s\n", pipex->command_arguments[pipex->i][i]);
                i++;
            }
        }
        pipex->i++;
    }
    if (pipex->command_arguments[0] && pipex->command_arguments[0][0]) {
        printf("First Command argument: %s\n", pipex->command_arguments[0][0]);
    }
}
