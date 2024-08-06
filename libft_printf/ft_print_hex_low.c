/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:37:35 by yashevch          #+#    #+#             */
/*   Updated: 2024/03/21 11:46:24 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_hex_low(unsigned int input)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (input >= 16)
	{
		i += ft_print_hex_low(input / 16);
		i += ft_print_hex_low(input % 16);
	}
	else
		i += ft_print_char(base[input]);
	return (i);
}
