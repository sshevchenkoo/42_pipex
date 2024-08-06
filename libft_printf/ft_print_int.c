/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:46:12 by yashevch          #+#    #+#             */
/*   Updated: 2024/03/21 11:48:25 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_int(int input)
{
	int	i;

	i = 0;
	if (input == -2147483648)
		return (write (1, "-2147483648", 11));
	if (input < 0)
	{
		i += write(1, "-", 1);
		input *= -1;
	}
	if (input > 9)
	{
		i += ft_print_int(input / 10);
		i += ft_print_int(input % 10);
	}
	else
		i += ft_print_char(input + 48);
	return (i);
}
