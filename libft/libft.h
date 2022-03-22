/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:28:06 by mleam             #+#    #+#             */
/*   Updated: 2022/03/22 15:32:41 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void	ft_putstr_fd(char *str, int fd);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strrev(char *str);
char	*ft_itoa_base(long value, char *base);
char	*ft_ultoa_base(unsigned long value, char *base);
void	ft_putchar(const char c);
void	ft_putstr(const char *str);

#endif