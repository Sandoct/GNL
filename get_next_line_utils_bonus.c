/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:39:01 by gpouzet           #+#    #+#             */
/*   Updated: 2022/11/28 21:39:04 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str) + 1;
	while (c > 256)
		c -= 256;
	while (i--)
		if (*str++ == c)
			return ((char *)--str);
	return (0);
}

char	*ft_join(char *s1, char *s2)
{
	char	*join;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (malloc(0));
	while (*s1)
		join[i++] = *s1++;
	while (*s2)
		join[i++] = *s2++;
	join[i] = '\0';
	return (join);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n--)
		*temp++ = c;
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = 0;
	if (!s)
		return (malloc(0));
	if (start >= ft_strlen(s))
		return (malloc(1));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = malloc(len + 1);
	if (!sub)
		return (malloc(0));
	while (start--)
		s++;
	while (*s && len--)
		sub[i++] = *s++;
	sub[i] = '\0';
	return (sub);
}
