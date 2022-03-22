/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa_int_up.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:22:14 by mleam             #+#    #+#             */
/*   Updated: 2022/03/22 15:41:03 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_hexa_int_up(va_list pt_arg)
{
	long			hexa_int_up;
	char			*tmp;
	size_t			len;

	hexa_int_up = (long) va_arg(pt_arg, unsigned int);
	tmp = ft_itoa_base(hexa_int_up, "0123456789ABCDEF");
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	free(tmp);
	return (len);
}
