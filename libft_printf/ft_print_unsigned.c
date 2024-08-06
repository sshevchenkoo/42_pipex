/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:56:38 by yashevch          #+#    #+#             */
/*   Updated: 2024/03/21 11:00:20 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_unsigned(unsigned int input)
{
	unsigned int	i;

	i = 0;
	if (input > 9)
	{
		i += ft_print_unsigned(input / 10);
		i += ft_print_unsigned(input % 10);
	}
	else
		i += ft_print_char(input + 48);
	return (i);
}
