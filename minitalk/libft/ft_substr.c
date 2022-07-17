/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:08:22 by taehooki          #+#    #+#             */
/*   Updated: 2022/05/09 15:43:43 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len)
		tmp = (char *)malloc(sizeof(char) * ((len = s_len) + 1));
	else
		tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !(tmp))
		return (NULL);
	if ((size_t)start >= s_len || !(ft_strlcpy(tmp, s + start, len + 1)))
		tmp[0] = '\0';
	return (tmp);
}
