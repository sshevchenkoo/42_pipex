/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:00:18 by yashevch          #+#    #+#             */
/*   Updated: 2024/03/08 12:09:09 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	l;

	l = 0;
	if (!s1 && !s2)
		return (s1);
	if (s1 > s2)
	{
		l = n;
		while (l > 0)
		{
			l--;
			((unsigned char *)s1)[l] = ((unsigned char *)s2)[l];
		}
	}
	else
	{
		l = 0;
		while (l < n)
		{
			((unsigned char *)s1)[l] = ((unsigned char *)s2)[l];
			l++;
		}
	}
	return (s1);
}
