/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:05:23 by erho              #+#    #+#             */
/*   Updated: 2023/11/08 16:38:06 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_nbrlen_base(unsigned long long n, int base_nb);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		conv_nbr(char *base, unsigned int n, int base_nb);
int		ft_putnbr_base(int nbr, char *base);
size_t	ft_strlen(const char *str);
int		ft_printf(const char *str, ...);
int		print_format(char c, va_list *argptr);
int		print_hex_addr(unsigned long long nbr);
int		conv_hex(char *base, unsigned long long n);
int		print_hex(char c, unsigned int nbr);

#endif
