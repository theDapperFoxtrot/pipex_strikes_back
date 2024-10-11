/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:16:54 by smishos           #+#    #+#             */
/*   Updated: 2024/10/11 14:20:16 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process1(t_pipex *pipex, char **argv, char **envp)
{
	close(pipex->fd[0]);
	dup2(pipex->fd[1], STDOUT_FILENO);
	close(pipex->fd[1]);
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1 && access(argv[1], F_OK))
		error_exit(pipex, argv[1], "No such file or directory\n", 0);
	else if (pipex->infile == -1 && access(argv[1], R_OK))
		error_exit(pipex, argv[1], "Permission denied\n", 0);
	pipex->exec_args1 = ft_split(argv[2], ' ');
	if (argv[2][0] == '\0' || argv[2][0] == ' ')
		error_exit(pipex, argv[2], "command not found\n", 0);
	ft_parse_commands(pipex, envp, argv[2 + pipex->i]);
	dup2(pipex->infile, STDIN_FILENO);
	close(pipex->infile);
	execve(pipex->cmd_args1[0], pipex->exec_args1, envp);
	if (access(argv[2], F_OK) == -1)
		error_exit(pipex, argv[2], "No such file or directory\n", 127);
	if (access(argv[2], X_OK) == -1)
		error_exit(pipex, argv[2], "Permission denied\n", 126);
	error_exit(pipex, argv[2], "Is a directory\n", 0);
}

void	child_process2(t_pipex *pipex, char **argv, int argc, char **envp)
{
	close(pipex->fd[1]);
	dup2(pipex->fd[0], STDIN_FILENO);
	close(pipex->fd[0]);
	pipex->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->outfile == -1 && access(argv[argc - 1], F_OK))
		error_exit(pipex, argv[argc - 1], "No such file or directory\n", 1);
	else if (pipex->outfile == -1 && access(argv[argc - 1], W_OK))
		error_exit(pipex, argv[argc - 1], "Permission denied\n", 1);
	pipex->exec_args2 = ft_split(argv[argc - 2], ' ');
	if (argv[argc - 2][0] == '\0' || argv[argc - 2][0] == ' ')
		error_exit(pipex, argv[argc - 2], "command not found\n", 127);
	ft_parse_commands(pipex, envp, argv[2 + pipex->i]);
	dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->outfile);
	execve(pipex->cmd_args2[0], pipex->exec_args2, envp);
	if (access(argv[argc - 2], F_OK) == -1)
		error_exit(pipex, argv[argc - 2], "No such file or directory\n", 127);
	if (access(argv[argc - 2], X_OK) == -1)
		error_exit(pipex, argv[argc - 2], "Permission denied\n", 126);
	error_exit(pipex, argv[argc - 2], "Is a directory\n", 126);
}

void	execute_loop(t_pipex *pipex, int argc, char **argv, char **envp)
{
	while (pipex->i < pipex->command_count)
	{
		pipex->pid[pipex->i] = (pid_t) fork();
		if (pipex->pid[pipex->i] < 0)
			error_exit(pipex, NULL, "Fork was unsuccessful", 1);
		if (pipex->pid[pipex->i] == 0 && pipex->i == 0)
			child_process1(pipex, argv, envp);
		if (pipex->pid[pipex->i] == 0 && pipex->i == 1)
			child_process2(pipex, argv, argc, envp);
		pipex->i++;
	}
}

void	close_fds(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

int	handle_exit(t_pipex *pipex)
{
	int		status;
	int		exit_code;
	int		child_pid;

	while (pipex->i < 2)
	{
		child_pid = waitpid(-1, &status, 0);
		if (WIFEXITED(status) && child_pid == pipex->pid[1])
			exit_code = WEXITSTATUS(status);
		pipex->i++;
	}
	return (exit_code);
}
