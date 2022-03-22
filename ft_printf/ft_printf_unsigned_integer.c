/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_integer.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:03:36 by mleam             #+#    #+#             */
/*   Updated: 2022/03/22 15:40:44 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_unsigned_integer(va_list pt_arg)
{
	long	unsigned_integer;
	char	*tmp;
	size_t	len;

	unsigned_integer = va_arg(pt_arg, unsigned int);
	tmp = ft_itoa_base(unsigned_integer, "0123456789");
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	free (tmp);
	return (len);
}
