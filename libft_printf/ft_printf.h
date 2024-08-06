/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:25:56 by yashevch          #+#    #+#             */
/*   Updated: 2024/03/21 11:57:59 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_hex_low(unsigned int input);
int	ft_print_hex_upper(unsigned int input);
int	ft_print_int(int input);
int	ft_print_pointer(unsigned long input);
int	ft_print_str(char *str);
int	ft_print_unsigned(unsigned int input);

#endif
