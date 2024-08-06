/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:23:52 by yashevch          #+#    #+#             */
/*   Updated: 2024/03/11 16:54:23 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	char	*new_line;

	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (ft_set(((char)*s1), set) == 1)
			s1++;
		else
			break ;
	}
	size = ft_strlen(s1);
	while (size != 0)
	{
		if (ft_set(s1[size - 1], set) == 1)
			size--;
		else
			break ;
	}
	new_line = malloc(size + 1);
	if (!new_line)
		return (NULL);
	ft_strlcpy(new_line, (char *)s1, size + 1);
	return (new_line);
}
