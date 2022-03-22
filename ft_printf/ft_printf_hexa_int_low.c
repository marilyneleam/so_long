/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa_int_low.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:25:50 by mleam             #+#    #+#             */
/*   Updated: 2022/03/22 15:41:02 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_hexa_int_low(va_list pt_arg)
{
	long			hexa_int_low;
	char			*tmp;
	size_t			len;

	hexa_int_low = (long) va_arg(pt_arg, unsigned int);
	tmp = ft_ultoa_base(hexa_int_low, "0123456789abcdef");
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	free(tmp);
	return (len);
}
