/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:19:18 by taehooki          #+#    #+#             */
/*   Updated: 2022/05/09 15:37:11 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_signcheck(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	ft_digitcheck(int n)
{
	int	count;

	count = 0;
	if (!n)
		return (1);
	while (n)
	{
		n = n / 10;
		++count;
	}
	return (count);
}

static void	ft_fillnum(unsigned int n, int digit, int sign, char	*result)
{
	*(result + (digit--) + sign) = '\0';
	while (digit >= 0)
	{
		*(result + digit + sign) = '0' + n % 10;
		n /= 10;
		--digit;
	}
	if (sign)
		*(result) = '-';
}

char	*ft_itoa(int n)
{
	unsigned int	abs;
	char			*result;
	int				sign;
	int				digit;

	sign = ft_signcheck(n);
	digit = ft_digitcheck(n);
	result = (char *)malloc(sizeof(char) * (sign + digit + 1));
	if (!(result))
		return (NULL);
	if (sign)
		abs = -n;
	else
		abs = n;
	ft_fillnum(abs, digit, sign, result);
	return (result);
}
