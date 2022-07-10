/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:32:50 by taehooki          #+#    #+#             */
/*   Updated: 2022/07/10 11:32:38 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len && s[len] != (unsigned char)c)
		--len;
	if (s[len] == (unsigned char)c)
		return ((char *)(s + len));
	return (NULL);
}
