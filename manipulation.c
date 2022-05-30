#include "cub3d.h"

static void	ft_find_delta(double *x, double *y, double dir, int keycode)
{
	if (keycode == 13)
	{
		*x = MOVE_SPEED * cos(dir);
		*y = -MOVE_SPEED * sin(dir);
	}
	else if (keycode == 1)
	{
		*x = -MOVE_SPEED * cos(dir);
		*y = MOVE_SPEED * sin(dir);
	}
	else if (keycode == 0)
	{
		*x = -MOVE_SPEED * sin(dir);
		*y = MOVE_SPEED * -cos(dir);
	}
	else if (keycode == 2)
	{
		*x = MOVE_SPEED * sin(dir);
		*y = -MOVE_SPEED * -cos(dir);
	}
}

void	ft_do_wasd(t_map *map, int keycode)
{
	int		posx;
	int		posy;
	double	deltax;
	double	deltay;
	
	ft_find_delta(&deltax, &deltay, map->pers.dir, keycode);
	posx = (int)(map->pers.pos_x + deltax + MOVE_SPEED * deltax / fabs(deltax));
	posy = (int)(map->pers.pos_y + deltay + MOVE_SPEED * deltay / fabs(deltay));
	if (map->map[(int)map->pers.pos_y][posx] != '1')
		map->pers.pos_x += deltax;
	if (map->map[posy][(int)map->pers.pos_x] != '1')
		map->pers.pos_y += deltay;
}

void	ft_do_rotate(double *dir, int keycode)
{
	if (keycode == 123)
		*dir += 0.06981317;
	else
		*dir -= 0.06981317;
	if (*dir < 0.0)
		*dir = 3.14159265 * 2 - 0.06981317;
	else if (*dir > 3.14159265 * 2)
		*dir = 0.00001;
}

void	ft_check_buttons(t_map *map)
{
	if (map->keys.w)
		ft_do_wasd(map, 13);
	if (map->keys.a)
		ft_do_wasd(map, 0);
	if (map->keys.s)
		ft_do_wasd(map, 1);
	if (map->keys.d)
		ft_do_wasd(map, 2);
	if (map->keys.left)
		ft_do_rotate(&map->pers.dir, 123);
	if (map->keys.right)
		ft_do_rotate(&map->pers.dir, 124);
}
