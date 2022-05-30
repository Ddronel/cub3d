#include "cub3d.h"

typedef struct s_local
{
	double	cur_x;
	double	cur_y;
	double	step_x;
	double	step_y;
	int		dif_x;
	int		dif_y;
	double	pos_x;
	double	pos_y;
	double	dir;
}	t_local_fun;

static double	find_wall_on_y(t_map *map, t_local_fun *q)
{
	printf("%d\n", map->map_width);
	if (q->cur_x >= map->map_width)
		q->cur_x = map->map_width - 1;
	if (q->cur_x < 0)
		q->cur_x = 0;
	printf("dif %d\n", q->dif_y);
	printf("cur y %f\n", q->cur_y);
	printf("cur x %f\n", q->cur_x);
	printf("%d\n",map->map[3][24]);
	printf("sum %d\n", (int)q->cur_y + q->dif_y);
	while (map->map[(int)q->cur_x][(int)q->cur_y + q->dif_y] != '1')
	{
		q->cur_y += q->step_y;
		q->cur_x = (q->pos_y - q->cur_y) / tan(q->dir) + q->pos_x;
		if (q->cur_x >= map->map_width)
			q->cur_x = map->map_width - 1;
		if (q->cur_x < 0)
			q->cur_x = 0;
	}
	return (sqrt((q->cur_x - q->pos_x) * (q->cur_x - q->pos_x)
				 + (q->cur_y - q->pos_y) * (q->cur_y - q->pos_y)));
}

double	cast_on_y(t_map *map, double posx, double posy, double dir)
{
	t_local_fun	q;
	
	q.dif_y = 0;
	if (dir < PI && dir > 0)
	{
		q.cur_y = floor(posy);
		q.cur_x = (posy - q.cur_y) / tan(dir) + posx;
		q.step_y = -1;
		q.dif_y = -1;
	}
	else if (dir == 0 || dir == PI)
	{
		q.cur_x = posx;
		q.cur_y = posy;
	}
	else
	{
		q.cur_y = ceil(posy);
		q.cur_x = (posy - q.cur_y) / tan(dir) + posx;
		q.step_y = 1;
	}
	q.pos_x = posx;
	q.pos_y = posy;
	q.dir = dir;
	return (find_wall_on_y(map, &q));
}

static double	find_wall_on_x(t_map *map, t_local_fun *q)
{
	if (q->cur_y >= map->map_height)
		q->cur_y = map->map_height - 1;
	if (q->cur_y < 0)
		q->cur_y = 0;
	while (map->map[(int)q->cur_y][(int)q->cur_x + q->dif_x] != '1')
	{
		q->cur_x += q->step_x;
		q->cur_y = (q->cur_x - q->pos_x) * -tan(q->dir) + q->pos_y;
		if (q->cur_y >= map->map_height)
			q->cur_y = map->map_height - 1;
		if (q->cur_y < 0)
			q->cur_y = 0;
	}
	return (sqrt((q->cur_x - q->pos_x) * (q->cur_x - q->pos_x)
				 + (q->cur_y - q->pos_y) * (q->cur_y - q->pos_y)));
}
/*
 * finds closest VERTICALLY wall crossing X coordinate towards view direction
 */
double	cast_on_x(t_map *map, double posx, double posy, double dir)
{
	t_local_fun q;
	
	q.dif_x = 0;
	if (dir > PI2 && dir < 1.5 * PI)
	{
		q.cur_x = floor(posx);
		q.cur_y = (q.cur_x - posx) * -tan(dir) + posy;
		q.step_x = -1;
		q.dif_x = -1;
	} else if (dir == PI2 || dir == PI2 * 3)
	{
		q.cur_x = posx;
		q.cur_y = posy;
	} else
	{
		q.cur_x = ceil(posx);
		q.cur_y = (q.cur_x - posx) * -tan(dir) + posy;
		q.step_x = 1;
	}
	q.pos_x = posx;
	q.pos_y = posy;
	q.dir = dir;
	return (find_wall_on_x(map, &q));
}
