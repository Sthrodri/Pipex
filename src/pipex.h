/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrodri <sthrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:36:16 by sthrodri          #+#    #+#             */
/*   Updated: 2025/01/13 13:36:18 by sthrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

int		ft_open_files(char *file, int file_in_or_file_out);
void	free_double_array(char **array);
char	*ft_get_command_path(char *cmd, char **envp);
char	*ft_custom_getenv(char *name, char **envp);
char	*ft_check_executable(char *cmd);

#endif
