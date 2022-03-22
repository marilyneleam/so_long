/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:40:25 by mleam             #+#    #+#             */
/*   Updated: 2022/03/22 15:40:38 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	pt_arg;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	va_start(pt_arg, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			len++;
		}
		else
		{
			i++;
			len += ft_printf_call(&format[i], pt_arg);
		}
		i++;
	}
	va_end(pt_arg);
	return (len);
}
