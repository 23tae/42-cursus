/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:47:27 by taehooki          #+#    #+#             */
/*   Updated: 2022/07/10 20:15:58 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(unsigned int n, char c)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_print_hex(n / 16, c);
	if (c == 'x')
		len += write(1, &"0123456789abcdef"[n % 16], 1);
	else if (c == 'X')
		len += write(1, &"0123456789ABCDEF"[n % 16], 1);
	return (len);
}

static int	ft_addr_to_hex(unsigned long n, char c)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_addr_to_hex(n / 16, c);
	if (c == 'x')
		len += write(1, &"0123456789abcdef"[n % 16], 1);
	else if (c == 'X')
		len += write(1, &"0123456789ABCDEF"[n % 16], 1);
	return (len);
}

int	ft_print_ptr(void	*addr)
{
	int	len;

	len = 0;
	write(1, "0x", 2);
	len = 2 + ft_addr_to_hex((unsigned long)addr, 'x');
	return (len);
}
