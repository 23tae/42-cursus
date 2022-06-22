/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:54:11 by taehooki          #+#    #+#             */
/*   Updated: 2022/06/22 18:24:22 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int	ft_print_str(char *str);
int	ft_print_char(char c);

int	ft_print_dec(int n);
int	ft_print_dec_unsigned(unsigned int n);

int	ft_print_hex(unsigned int n, char c);
int	ft_print_ptr(void *addr);

int	ft_printf(const char *format, ...);
#endif
