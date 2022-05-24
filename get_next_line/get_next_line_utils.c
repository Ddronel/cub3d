/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:24:06 by eveiled           #+#    #+#             */
/*   Updated: 2021/10/17 12:24:08 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	size;

	size = 0;
	if (!str)
		return (size);
	while (*str)
	{
		size++;
		str++;
	}
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*join;
	int			count;
	char const	*saver;
	char const	*saver_s2;

	saver = s1;
	saver_s2 = s2;
	count = 0;
	join = (char *)malloc(sizeof(char)
			* (ft_strlen((char *)s1) + ft_strlen((char *)s2)) + 1);
	if (NULL == join)
		return (NULL);
	if (s1)
	{
		while (*s1)
			join[count++] = *s1++;
		free((void *)saver);
	}
	while (*s2)
		join[count++] = *s2++;
	join[count] = '\0';
	ft_bzero((char *)saver_s2, ft_strlen((char *)saver_s2));
	return (join);
}

void	*ft_bzero(void *s, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		*((unsigned char *)(s + counter)) = '\0';
		counter++;
	}
	return (s);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	counter;

	counter = 0;
	if (src == NULL && dst == NULL)
		return (NULL);
	while (counter < n)
	{
		((unsigned char *)dst)[counter] = ((unsigned char *)src)[counter];
		counter++;
	}
	return (dst);
}
