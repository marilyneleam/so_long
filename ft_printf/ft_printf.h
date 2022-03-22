/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:19:10 by mleam             #+#    #+#             */
/*   Updated: 2021/08/18 15:53:15 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
size_t	ft_printf_call(const char *str, va_list pt_arg);
size_t	ft_printf_character_percent(const char *str, va_list pt_arg);
size_t	ft_printf_string(const char *str, va_list pt_arg);
size_t	ft_printf_decimal_integer(va_list pt_arg);
size_t	ft_printf_unsigned_integer(va_list pt_arg);
size_t	ft_printf_hexa_int_low(va_list pt_arg);
size_t	ft_printf_hexa_int_up(va_list pt_arg);
size_t	ft_printf_adress(va_list pt_arg);

#endif
