/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:17:57 by taehooki          #+#    #+#             */
/*   Updated: 2022/06/03 21:55:04 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	tmp = (char *)malloc(len_s1 + len_s2 + 1);
	if (!(tmp))
		return (NULL);
	ft_memcpy(tmp, s1, len_s1);
	ft_memcpy(tmp + len_s1, s2, len_s2);
	tmp[len_s1 + len_s2] = '\0';
	return (tmp);
}
