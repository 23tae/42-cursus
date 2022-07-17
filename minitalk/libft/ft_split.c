/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:19:06 by taehooki          #+#    #+#             */
/*   Updated: 2022/05/09 15:41:13 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordnum(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			++count;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (count);
}

static void	ft_free(char **result, size_t word)
{
	size_t	i;

	i = 0;
	while (i < word)
	{
		free(*(result + i));
		i++;
	}
	free(result);
}

static int	ft_cutword(char const *s, char c, char **result, size_t word)
{
	size_t	idx1;
	size_t	idx2;

	idx1 = 0;
	while (*(s + idx1))
	{
		if (*(s + idx1) == c)
			idx1++;
		else
		{
			idx2 = 0;
			while (*(s + idx1 + idx2) != c && *(s + idx1 + idx2))
				idx2++;
			*(result + word) = (char *)malloc(idx2 + 1);
			if (!(*(result + word)))
			{
				ft_free(result, word);
				return (0);
			}
			ft_memcpy(*(result + word), s + idx1, idx2);
			*(*(result + (word++)) + idx2) = 0;
			idx1 += idx2;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**result;

	if (!s)
		return (NULL);
	count = ft_wordnum(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!(result))
		return (NULL);
	*(result + count) = NULL;
	if (!ft_cutword(s, c, result, 0))
		return (NULL);
	return (result);
}
