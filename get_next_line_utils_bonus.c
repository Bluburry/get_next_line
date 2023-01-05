/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:36:30 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/01/04 17:36:31 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*(char *) s == (char) c)
		{
			return ((char *) s);
		}
		s++;
	}
	return (NULL);
}

void	*ft_memcpy(char *dest, const char *src, size_t n)
{
	void	*ptr;

	ptr = dest;
	if (!dest && !src)
		return (NULL);
	dest[n] = 0;
	while (n--)
	{
		*(char *)dest++ = *(char *)src++;
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	string = (char *) malloc((i + j + 1) * sizeof(char));
	if (!string)
		return (NULL);
	ft_memcpy(string, s1, i);
	ft_memcpy(string + i, s2, j);
	string[i + j] = 0;
	return (string);
}
