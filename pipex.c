/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedapperfoxtrot <thedapperfoxtrot@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:16:54 by smishos           #+#    #+#             */
/*   Updated: 2024/10/10 01:37:16 by thedapperfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process1(t_pipex *pipex, char **argv, char **envp)
{
	char	**exec_args1;

	exec_args1 = ft_split(argv[2], ' ');
	if (argv[2][0] == '\0' || argv[2][0] == ' ')
		error_exit(pipex, argv[2], "command not found\n", 0);
	ft_parse_commands(pipex, envp, argv[2 + pipex->i], exec_args1);
	close(pipex->fd[0]);
	close(pipex->outfile);
	dup2(pipex->infile, STDIN_FILENO);
	close(pipex->infile);
	dup2(pipex->fd[1], STDOUT_FILENO);
	close(pipex->fd[1]);
	execve(pipex->cmd_args1[0], exec_args1, envp);
	free_split(exec_args1);
	if (access(argv[2], F_OK) == -1)
		error_exit(pipex, argv[2], "No such file or directory\n", 127);
	if (access(argv[2], X_OK) == -1)
		error_exit(pipex, argv[2], "Permission denied\n", 126);
	error_exit(pipex, argv[2], "Is a directory\n", 0);
}

void	child_process2(t_pipex *pipex, char **argv, int argc, char **envp)
{
	char	**exec_args2;

	exec_args2 = ft_split(argv[argc - 2], ' ');
	if (argv[argc - 2][0] == '\0' || argv[argc - 2][0] == ' ')
		error_exit(pipex, argv[argc - 2], "command not found\n", 127);
	ft_parse_commands(pipex, envp, argv[2 + pipex->i], exec_args2);
	close(pipex->fd[1]);
	close(pipex->infile);
	dup2(pipex->fd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->outfile);
	close(pipex->fd[0]);
	execve(pipex->cmd_args2[0], exec_args2, envp);
	free_split(exec_args2);
	if (access(argv[argc - 2], F_OK) == -1)
		error_exit(pipex, argv[argc - 2], "No such file or directory\n", 127);
	if (access(argv[argc - 2], X_OK) == -1)
		error_exit(pipex, argv[argc - 2], "Permission denied\n", 126);
	error_exit(pipex, argv[argc - 2], "Is a directory\n", 126);
}

void	execute_loop(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->i = 0;
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
	close(pipex->infile);
	close(pipex->outfile);
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
		{
			exit_code = WEXITSTATUS(status);
			break ;
		}
		pipex->i++;
	}
	return (exit_code);
}
