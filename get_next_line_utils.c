/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:54:08 by jdussert          #+#    #+#             */
/*   Updated: 2019/11/15 11:15:02 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tab;
	size_t			i;

	i = 0;
	if (size == 0 && count == 0)
	{
		size = 1;
		count = 1;
	}
	if (!(tab = (unsigned char *)malloc(size * count)))
		return (NULL);
	while (i < count * size)
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (!n || src == dst)
		return (dst);
	while (i < n)
	{
		*(char *)dst = *(char *)src;
		dst++;
		src++;
		i++;
	}
	return (dst - i);
}

char	*ft_strchr(char *s, char c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (s);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (s1[i])
		i++;
	if (!(s2 = malloc(sizeof(*s2) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;
	int		c;

	j = 0;
	if (s1)
	{
		i = ft_strlen((char *)s1);
		if (s2)
			j = i + ft_strlen((char *)s2);
		c = 0;
		if (!(dst = malloc(sizeof(char *) * (j + 1))))
			return (NULL);
		ft_memcpy(dst, s1, i);
		while (s1 && s2 && i < j)
			dst[i++] = s2[c++];
		dst[i] = '\0';
		return (dst);
	}
	else
		return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*dst;
	size_t		i;
	size_t		s_len;

	i = 0;
	if (s)
	{
		s_len = ft_strlen((char *)s);
		if ((dst = (char *)ft_calloc(len + 1, sizeof(*dst))) == NULL)
			return (NULL);
		if (start < s_len)
			while (i < len && s[start])
				dst[i++] = s[start++];
		return (dst);
	}
	else
		return (NULL);
}
