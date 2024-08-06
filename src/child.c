/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:45:17 by yashevch          #+#    #+#             */
/*   Updated: 2024/04/13 13:41:00 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**find_paths(char **envp)
{
	char	**paths;
	char	*path;

	path = NULL;
	paths = NULL;
	while (envp && *envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			path = ft_strdup(&(*envp)[5]);
			break ;
		}
		envp++;
	}
	paths = ft_split(path, ':');
	if (path)
		free(path);
	return (paths);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*result;
	char	**allpath;
	char	*tmp;

	i = 0;
	allpath = find_paths(envp);
	while (allpath[i])
	{
		tmp = ft_strjoin(allpath[i], "/");
		result = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(result, F_OK | X_OK) == 0)
			return (result);
		free(result);
		i++;
	}
	ft_free_tab(allpath);
	return (cmd);
}
