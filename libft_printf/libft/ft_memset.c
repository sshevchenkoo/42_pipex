/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:36:39 by yashevch          #+#    #+#             */
/*   Updated: 2024/02/27 19:44:36 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	while (n > 0)
	{
		((unsigned char *)dest)[n - 1] = (unsigned char)c;
		n--;
	}
	return (dest);
}
