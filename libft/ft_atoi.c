/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:42:00 by                   #+#    #+#             */
/*   Updated: 2021/10/11 14:28:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_message_invalid_RGB(char *line)
{
	write(1, "Invalid RGB color in ", 21);
	write(1, line, 1);
	write(1, "\n", 1);
	exit (1);
}

int	ft_atoi(char *str)
{
	long int	ans;
	int			zn;

	ans = 0;
	zn = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == ',')
		ft_message_invalid_RGB(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			zn = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		ans = ans * 10 + *str - '0';
		str++;
	}
	ans = ans * zn;
	return (ans);
}
