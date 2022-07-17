/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:36:34 by taehooki          #+#    #+#             */
/*   Updated: 2022/07/14 22:43:18 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoin(char *str, char c)
{
	char	*ptr;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	ptr = malloc(len + 2);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, str, len);
	ptr[len] = c;
	ptr[len + 1] = '\0';
	free(str);
	return (ptr);
}
