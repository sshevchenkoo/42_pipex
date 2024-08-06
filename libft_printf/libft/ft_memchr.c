/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:35:47 by yashevch          #+#    #+#             */
/*   Updated: 2024/02/27 19:40:55 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	nc;

	i = 0;
	str = (unsigned char *)s;
	nc = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == nc)
			return ((void *)(str + i));
		i++;
	}
	return (0);
}
