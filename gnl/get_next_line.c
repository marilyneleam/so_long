/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:48:58 by mleam             #+#    #+#             */
/*   Updated: 2022/02/25 16:37:07 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(char const *str, char const c)
{
	while (*str && *str != c)
		++str;
	if (*str == c)
		return ((char *)str);
	return (NULL);
}

char	*before_line(char *str)
{
	int		i;
	char	*line;
	char	*newline;
	size_t	len;

	newline = ft_strchr(str, '\n');
	if (!newline)
		len = ft_strlen(str);
	else
		len = newline - str;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	free(str);
	return (line);
}

static void	after_line(char *stock, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i])
		++i;
	while (line[i])
		stock[j++] = line[i++];
	stock[j] = '\0';
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	stock[BUFFER_SIZE + 1];
	int			ret;

	ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = ft_strdup(stock);
	while (!ft_strchr(*line, '\n') && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	after_line((char *)stock, *line);
	*line = before_line(*line);
	if (ret == 0)
		return (0);
	return (1);
}
