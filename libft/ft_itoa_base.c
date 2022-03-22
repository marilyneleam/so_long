/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 06:09:44 by mleam             #+#    #+#             */
/*   Updated: 2021/08/23 17:19:16 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_len(long n)
{
	int		count;

	count = 0;
	if (n < 0)
	{
		n *= (-1);
		count++;
	}
	if (n == 0)
		count++;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa_base(long value, char *base)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	if (value < 0)
		value *= -1;
	if (value == 0)
		return (ft_strdup("0"));
	str = malloc(sizeof(char) * (ft_count_len(value) + 1));
	len = ft_strlen(base);
	if (!str)
		return (NULL);
	while (value != 0)
	{
		str[i++] = base[value % len];
		value = value / len;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
