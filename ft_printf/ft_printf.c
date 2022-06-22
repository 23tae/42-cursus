/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:00:30 by taehooki          #+#    #+#             */
/*   Updated: 2022/06/22 18:22:58 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse_type(char type, va_list *ap)
{
	int	count;

	count = 0;
	if (type == 'c')
		count = ft_print_char(va_arg(*ap, int));
	else if (type == 's')
		count = ft_print_str(va_arg(*ap, char *));
	else if (type == 'p')
		count = ft_print_ptr(va_arg(*ap, void *));
	else if (type == 'd' || type == 'i')
		count = ft_print_dec(va_arg(*ap, int));
	else if (type == 'u')
		count = ft_print_dec_unsigned(va_arg(*ap, unsigned int));
	else if (type == 'x' || type == 'X')
		count = ft_print_hex(va_arg(*ap, unsigned int), type);
	else
		count = write(1, &type, 1);
	return (count);
}

static int	ft_parse_format(char *format, va_list *ap)
{
	int	count;

	count = 0;
	while (*format)
	{
		if (*format != '%')
		{
			count += write(1, format++, 1);
			continue ;
		}
		++format;
		if (!*format)
			break ;
		count += ft_parse_type(*format, ap);
		++format;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;

	count = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	count = ft_parse_format((char *)format, &ap);
	va_end(ap);
	return (count);
}
