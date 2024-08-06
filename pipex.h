/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:30:19 by yashevch          #+#    #+#             */
/*   Updated: 2024/04/13 21:03:43 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft_printf/ft_printf.h"

typedef struct s_pipex
{
	int		read;
	int		write;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;
void	ft_free_tab(char **tab);
char	**find_paths(char **envp);
char	*get_path(char *cmd, char **envp);
void	ft_free_tab(char **tab);
#endif
