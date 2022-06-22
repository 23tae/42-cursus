/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:33:19 by taehooki          #+#    #+#             */
/*   Updated: 2022/05/09 15:43:11 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nd_len;

	nd_len = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && nd_len <= len--)
	{
		if (*haystack == *needle && !ft_memcmp(haystack, needle, nd_len))
			return ((char *)haystack);
		++haystack;
	}
	return (NULL);
}
