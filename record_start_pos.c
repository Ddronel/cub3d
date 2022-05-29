#include "cub3d.h"

void ft_find_start_pos(t_map *s_map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (s_map->map[x])
	{
		y = 0;
		while (s_map->map[x][y])
		{
			if (s_map->map[x][y] == 'N' || s_map->map[x][y] == 'S' || s_map->map[x][y] == 'W' || s_map->map[x][y] == 'E')
			{
				s_map->pers.pos_x = (double)(x + 0.5);
				s_map->pers.pos_y = (double)(y + 0.5);
				printf("%d%d", x, y);
				if (s_map->map[x][y] == 'N')
					s_map->pers.dir = PI2;
				else if (s_map->map[x][y] == 'W')
					s_map->pers.dir = PI;
				else if (s_map->map[x][y] == 'S')
					s_map->pers.dir = PI + PI2;
				else if (s_map->map[x][y] == 'E')
					s_map->pers.dir = PI * 2;
				return ;
			}
			y++;
		}
		x++;
	}
	return ;
}