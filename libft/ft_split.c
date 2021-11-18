/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:02:45 by mleam             #+#    #+#             */
/*   Updated: 2021/11/18 15:49:24 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// int	ft_strlen(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

// char	*ft_strdup(char *s)
// {
// 	char	*d;
// 	int		i;

// 	i = 0;
// 	if (!(d = malloc(sizeof(char) * (ft_strlen(s) + 1))))
// 		return (NULL);
// 	while (s[i] != '\0')
// 	{
// 		d[i] = s[i];
// 		i++;
// 	}
// 	d[i] = '\0';
// 	return (d);
// }

// char	*ft_substr(char *s, int start, size_t len)
// {
//     size_t    count;
//     size_t    size;
//     char    *res;

//     if (!s)
//         return (NULL);
//     if (ft_strlen(s) < start)
//         return (ft_strdup(""));
//     size = ft_strlen(s + start);
//     if (size < len)
//         len = size;
//     res = (char *)malloc(sizeof(*res) * (len + 1));
//     if (!res)
//         return (NULL);
//     count = 0;
//     while (count < len)
//     {
//         res[count] = s[start + count];
//         count++;
//     }
//     res[count] = '\0';
//     return (res);
// }

static int	count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (s == 0)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free_split(char **a)
{
	size_t i;

	i = 0;
	if (a)
	{
		while (a[i])
		{
			free(a[i]);
			i++;
		}
		free(a);
	}
	return (NULL);
}

char		**ft_split(char *s, char c)
{
	char	**a;
	size_t	i;
	size_t	k;
	size_t	start;

	i = 0;
	k = 0;
	a = NULL;
	if (s == 0 || !(a = (char **)malloc(sizeof(char *) * (count(s, c) + 1))))
		return (ft_free_split(a));
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[start] != '\0' && !(a[k++] = ft_substr(s, start, i - start)))
			return (ft_free_split(a));
	}
	a[k] = NULL;
	return (a);
}

// int main()
// {
// 	char str[] = "CALL.ber";
// 	char **ptr = ft_split(str, '.');
// 	while (*ptr)
// 	{
// 		printf("%s\n", *ptr);
// 		*ptr++;
// 	}
// 	return (0);
// }