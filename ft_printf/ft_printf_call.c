/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_call.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:00:49 by mleam             #+#    #+#             */
/*   Updated: 2022/03/22 15:41:24 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_call(const char *str, va_list pt_arg)
{
	size_t	len;

	len = 0;
	if (*str == 'c' || *str == '%')
		len = ft_printf_character_percent(str, pt_arg);
	else if (*str == 's')
		len = ft_printf_string(str, pt_arg);
	else if (*str == 'd' || *str == 'i')
		len = ft_printf_decimal_integer(pt_arg);
	else if (*str == 'u')
		len = ft_printf_unsigned_integer(pt_arg);
	else if (*str == 'x')
		len = ft_printf_hexa_int_low(pt_arg);
	else if (*str == 'X')
		len = ft_printf_hexa_int_up(pt_arg);
	else if (*str == 'p')
		len = ft_printf_adress(pt_arg);
	return (len);
}
