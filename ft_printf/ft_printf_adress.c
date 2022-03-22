/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_adress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:30:45 by mleam             #+#    #+#             */
/*   Updated: 2022/03/22 15:41:21 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_adress(va_list pt_arg)
{
	long	adress;
	char	*tmp;
	size_t	len;

	adress = (long) va_arg(pt_arg, void *);
	tmp = ft_ultoa_base(adress, "0123456789abcdef");
	ft_putstr("0x");
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	free(tmp);
	return (len + 2);
}
