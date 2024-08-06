/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:50:37 by yashevch          #+#    #+#             */
/*   Updated: 2024/03/21 13:16:06 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_check_format(const char *format, va_list input)
{
	int	i;

	i = 0;
	if (*format == 'c')
		i += ft_print_char(va_arg(input, int));
	else if (*format == 's')
		i += ft_print_str(va_arg(input, char *));
	else if (*format == 'p')
		i += ft_print_pointer(va_arg(input, unsigned long));
	else if (*format == 'd')
		i += ft_print_int(va_arg(input, int));
	else if (*format == 'i')
		i += ft_print_int(va_arg(input, int));
	else if (*format == 'u')
		i += ft_print_unsigned(va_arg(input, unsigned int));
	else if (*format == 'x')
		i += ft_print_hex_low(va_arg(input, unsigned int));
	else if (*format == 'X')
		i += ft_print_hex_upper(va_arg(input, unsigned int));
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX", *format))
				i += ft_check_format(format, args);
			else if (*format == '%')
				i += ft_print_char('%');
		}
		else
			i += ft_print_char(*format);
		format++;
	}
	va_end(args);
	return (i);
}
