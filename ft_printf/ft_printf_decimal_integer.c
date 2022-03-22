/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal_integer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:07:49 by mleam             #+#    #+#             */
/*   Updated: 2022/03/22 15:41:17 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_decimal_integer(va_list pt_arg)
{
	char	*tmp;
	int		decimal_integer;
	int		len;

	decimal_integer = va_arg(pt_arg, int);
	len = 0;
	if (decimal_integer < 0)
	{
		ft_putstr("-");
		len = 1;
	}
	tmp = ft_itoa_base(decimal_integer, "0123456789");
	ft_putstr(tmp);
	len += ft_strlen(tmp);
	free(tmp);
	return (len);
}
