/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:23:01 by eveiled           #+#    #+#             */
/*   Updated: 2021/11/08 14:35:13 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_nl_ckecker(char *buff)
{
	long int	counter;

	if (!buff)
		return (-1);
	counter = 0;
	while (buff[counter])
	{
		if (buff[counter] == '\n')
			return (counter);
		counter++;
	}
	return (-1);
}

char	*ft_big_str(char *str, char *buff)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\n')
		counter++;
	ft_memcpy(buff, (str + counter + 1), ft_strlen(str) - counter - 1);
	ft_bzero((str + counter), ft_strlen((str + counter)));
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	buff[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0)
		return (NULL);
	str = NULL;
	if (!buff[0])
		ft_bzero(buff, BUFFER_SIZE + 1);
	if (ft_nl_ckecker(buff) >= 0)
		return (ft_big_str(ft_strjoin(str, buff), buff));
	ret = 1;
	while (ret > 0)
	{
		if (!buff[0])
			ret = read(fd, buff, BUFFER_SIZE);
		str = ft_strjoin(str, buff);
		if (ft_nl_ckecker(str) >= 0)
			return (ft_big_str(str, buff));
	}
	if (str[0] != '\0' && ret == 0)
		return (ft_strjoin(str, buff));
	free(str);
	return (NULL);
}
