/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:47:36 by taehooki          #+#    #+#             */
/*   Updated: 2022/06/21 12:21:28 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
		len = write(1, "(null)", 6);
	else
		len = write(1, str, ft_strlen(str));
	return (len);
}

int	ft_print_char(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}
