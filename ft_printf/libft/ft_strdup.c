/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:33:18 by taehooki          #+#    #+#             */
/*   Updated: 2022/05/09 15:41:30 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	count;
	char	*result;

	count = ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * (count + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, count + 1);
	return (result);
}
