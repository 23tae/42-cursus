/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoverflow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:40:13 by taehooki          #+#    #+#             */
/*   Updated: 2022/07/11 17:46:28 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isoverflow(long long n)
{
	long long	max;
	long long	min;

	max = 2147483647;
	min = -2147483648;
	if (n > max)
		return (1);
	if (n < min)
		return (-1);
	else
		return (0);
}
