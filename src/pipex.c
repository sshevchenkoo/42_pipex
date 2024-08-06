/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:46:25 by yashevch          #+#    #+#             */
/*   Updated: 2024/04/13 13:40:08 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

void	ft_perror(char *err)
{
	perror(err);
	exit(0);
}

void	child1(char **argv, int *pipe_fd, char **envp, int fd)
{
	char	**args_cmd;
	char	*path;

	dup2(fd, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	args_cmd = ft_split(argv[2], ' ');
	if (args_cmd[0] == NULL)
	{
		free(args_cmd);
		perror("Empty First Command");
		exit(127);
	}
	path = get_path(args_cmd[0], envp);
	if (execve(path, args_cmd, envp) == -1)
	{
		perror("Error first command");
		ft_putendl_fd(args_cmd[0], 2);
		ft_free_tab(args_cmd);
		exit(127);
	}
}

void	child2(char **argv, int *pipe_fd, char **envp, int fd)
{
	char	**args_cmd;
	char	*path;

	dup2(fd, 1);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[1]);
	args_cmd = ft_split(argv[3], ' ');
	if (args_cmd[0] == NULL)
	{
		free(args_cmd);
		perror("Empty Second Command");
		exit(127);
	}
	path = get_path(args_cmd[0], envp);
	if (execve(path, args_cmd, envp) == -1)
	{
		perror("Error second command");
		ft_putendl_fd(args_cmd[0], 2);
		ft_free_tab(args_cmd);
		exit(127);
	}
}

void	close_pipex(int *pipe_fd)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	t_pipex	pipex;

	if (argc != 5)
		ft_perror("Please write ./pipex file1 cmd cmd file2");
	pipex.write = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex.write < 0)
		ft_perror("Error write file");
	pipex.read = open(argv[1], O_RDONLY, 0777);
	if (pipex.read < 0)
		ft_perror("Error read file");
	if (pipe(pipe_fd) == -1)
		exit(1);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		child1(argv, pipe_fd, envp, pipex.read);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		child2(argv, pipe_fd, envp, pipex.write);
	close_pipex(pipe_fd);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	close(pipex.read);
	close(pipex.write);
	return (0);
}
