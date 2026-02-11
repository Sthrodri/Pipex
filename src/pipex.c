/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrodri <sthrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:36:08 by sthrodri          #+#    #+#             */
/*   Updated: 2025/01/13 13:59:37 by sthrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(int n_exit)
{
	if (n_exit == 1)
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
} 
/*"Se o número de saída for 1
 exiba a mensagem 'Uso: ./pipex file1 cmd1 cmd2 file2'
 encerre o programa."*/

void	ft_exec(char *cmd, char **env)
{
	char	*cmd_path;
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
	{
		ft_putstr_fd("Error: Failed to parse command arguments.\n", 2);
		free_double_array(cmd_args);
		exit(127);
	}
	cmd_path = ft_get_command_path(cmd_args[0], env);
	if (!cmd_path)
	{
		ft_putstr_fd("Error: Command not found.\n", 2);
		free_double_array(cmd_args);
		exit(127);
	}
	if (execve(cmd_path, cmd_args, env) == -1)
	{
		perror("Error");
		free(cmd_path);
		free_double_array(cmd_args);
		exit(126);
	}
}
/*Tente executar o comando especificado pelo usuário
dividindo-o em argumentos separados por espaços.
Se a divisão dos argumentos falhar
exiba a mensagem 'Error: Failed to parse command arguments.
e encerre o programa com o código de saída 127.
Em seguida, procure pelo caminho do comando no ambiente fornecido.
Se o caminho do comando não for encontrado
exiba a mensagem 'Error: Command not found.
e encerre o programa com o código de saída 127.
tente executar o comando usando execve com o caminho do comando e os argumentos.
Se a execução do comando falhar
exiba uma mensagem de erro usando perror
libere a memória alocada 
encerre o programa com o código de saída 126.

*/

void	ft_child_process(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = ft_open_files(av[1], 0);
	if (fd == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDIN_FILENO) == -1 || dup2(p_fd[1], STDOUT_FILENO) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	close(fd);
	close(p_fd[0]);
	ft_exec(av[2], env);
}

void	ft_parent_process(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = ft_open_files(av[4], 1);
	if (fd == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDOUT_FILENO) == -1 || dup2(p_fd[0], STDIN_FILENO) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	close(fd);
	close(p_fd[1]);
	ft_exec(av[3], env);
}

int	main(int argc, char **argv, char **envp)
{
	int		p_fd[2];
	pid_t	process;

	if (argc != 5)
		ft_exit(1);
	if (pipe(p_fd) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	process = fork();
	if (process == -1)
		exit(EXIT_FAILURE);
	if (process == 0)
		ft_child_process(argv, p_fd, envp);
	else
		ft_parent_process(argv, p_fd, envp);
	return (EXIT_SUCCESS);
}
