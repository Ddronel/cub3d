#include "cub3d.h"

void ft_find_start_pos(t_map *s_map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	// printf("%d%d\n", x, y);
	while (s_map->map[x])
	{
		y = 0;
		while (s_map->map[x][y])
		{
			if (s_map->map[x][y] == 'N' || s_map->map[x][y] == 'S' || s_map->map[x][y] == 'W' || s_map->map[x][y] == 'E')
			{
				s_map->pers.pos_x = (double)x;
				s_map->pers.pos_y = (double)y;
				// s_map->map->pers->dir = (double)y ;
				printf("%d%d", x, y);
				return ;
			}
			// printf("%c\n", s_map->map[x][y]);
			y++;
		}
		// printf("%s", s_map->map[x]);
		x++;
	}
	return ;
}