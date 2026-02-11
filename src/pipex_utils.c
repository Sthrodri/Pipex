/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrodri <sthrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:35:55 by sthrodri          #+#    #+#             */
/*   Updated: 2025/01/13 13:36:01 by sthrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_check_executable(char *cmd)
{
	char	*result;

	if (access(cmd, X_OK) == 0)
		result = ft_strdup(cmd);
	else
		result = NULL;
	return (result);
}

int	ft_open_files(char *file, int file_in_or_file_out)
{
	int	fd;

	if (file_in_or_file_out == 0)
		fd = open(file, O_RDONLY, 0644);
	else if (file_in_or_file_out == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		return (-1);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

char	*ft_custom_getenv(char *name, char **envp)
{
	int		len;
	int		i;

	len = ft_strlen(name);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

char	*ft_get_command_path(char *cmd, char **envp)
{
	char	*path_env;
	char	**paths;
	char	*full_path;
	char	*temp_path;
	int		i;

	if (cmd[0] == '.' || cmd[0] == '/')
		return (ft_check_executable(cmd));
	path_env = ft_custom_getenv("PATH", envp);
	paths = ft_split(path_env, ':');
	if (!paths || !path_env)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		temp_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (access(full_path, X_OK | F_OK | R_OK) == 0)
			return (free_double_array(paths), full_path);
		free(full_path);
	}
	free_double_array(paths);
	return (NULL);
}

void	free_double_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
