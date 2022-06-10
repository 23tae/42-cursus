/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:31:12 by taehooki          #+#    #+#             */
/*   Updated: 2022/05/09 15:39:48 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*udst;
	unsigned char	*usrc;

	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	if (dst != src && len)
	{
		if (dst < src)
			while (len--)
				*udst++ = *usrc++;
		else
		{
			udst += len;
			usrc += len;
			while (len--)
				*--udst = *--usrc;
		}
	}
	return (dst);
}
