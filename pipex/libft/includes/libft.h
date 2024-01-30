/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:37:23 by erho              #+#    #+#             */
/*   Updated: 2024/01/20 16:29:54 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define MEMORY 50
# define WRITE 53

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"
# include "get_next_line.h"

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t len);
int		ft_putstr(char *s);
int		ft_putchar(char c);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_error(int error_no);
int		ft_strncmp(const char *s1, const char *s2, size_t len);

#endif