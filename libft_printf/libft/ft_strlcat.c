/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:50:36 by yashevch          #+#    #+#             */
/*   Updated: 2024/03/08 12:19:37 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d;

	i = 0;
	j = 0;
	d = 0;
	if ((!dest || !src) && !size)
		return (0);
	while (dest[i] != '\0')
		i++;
	while (src[d] != '\0')
		d++;
	if (!dest && size == 0)
		return (d);
	if (size <= i)
		return (size + d);
	while (i + j < size - 1 && src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + d);
}
