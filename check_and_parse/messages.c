/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:02:40 by eveiled           #+#    #+#             */
/*   Updated: 2021/11/08 15:03:31 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_message_cant_open(void)
{
	write(1, "Can't open file.\n", 17);
	exit (1);
}

void	ft_message_invalid_map(void)
{
	write(1, "Invalid map.\n", 13);
	exit (1);
}

void	ft_message_invalid_path(char *path)
{
    write(1, "Invalid path to ", 16);
    write(1, path, 2);
    write(1, " texture.\n", 10);
    exit (1);
}

void	ft_message_where_is_map(void)
{
	write(1, "Where is map?\n", 14);
	exit (1);
}

void    ft_message_invalid_RGB(char *line){
    write(1, "Invalid RGB color in ", 21);
    write(1, line, 1);
    write(1, "\n", 1);
    exit (1);
}
