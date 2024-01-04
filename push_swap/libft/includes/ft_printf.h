/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:05:23 by erho              #+#    #+#             */
/*   Updated: 2023/12/21 19:24:46 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

size_t	ft_nbrlen_base(unsigned long long n, int base_nb);
int		conv_nbr(char *base, unsigned int n, int base_nb);
int		ft_putnbr_base(int nbr, char *base);
int		ft_printf(const char *str, ...);
int		print_format(char c, va_list *argptr);
int		print_hex_addr(unsigned long long nbr);
int		conv_hex(char *base, unsigned long long n);
int		print_hex(char c, unsigned int nbr);

#endif