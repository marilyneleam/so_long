/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:17:13 by mleam             #+#    #+#             */
/*   Updated: 2021/08/23 17:21:48 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_size(unsigned long n)
{
	int		count;

	count = 0;
	if (n == 0)
		count++;
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

char	*ft_ultoa_base(unsigned long value, char *base)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	if (value == 0)
		return (ft_strdup("0"));
	str = malloc(sizeof(char) * (ft_count_size(value) + 1));
	len = ft_strlen(base);
	if (!str)
		return (NULL);
	while (value != 0)
	{
		str[i] = base[value % len];
		value = value / len;
		i++;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
