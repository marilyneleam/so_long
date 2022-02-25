/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:28:06 by mleam             #+#    #+#             */
/*   Updated: 2022/02/25 14:00:26 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void	ft_putstr_fd(char *str, int fd);
char	*ft_substr(char *s, int start, size_t len);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);

#endif