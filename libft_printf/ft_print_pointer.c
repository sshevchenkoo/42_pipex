/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:52:54 by yashevch          #+#    #+#             */
/*   Updated: 2024/03/21 19:04:51 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_pointer(unsigned long input)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (input >= 16)
	{
		i += ft_pointer(input / 16);
		i += ft_pointer(input % 16);
	}
	else
		i += ft_print_char(base[input]);
	return (i);
}

int	ft_print_pointer(unsigned long input)
{
	if (input == 0)
		return (write (1, "(nil)", 5));
	else
	{
		write (1, "0x", 2);
		return (ft_pointer(input) + 2);
	}
}
