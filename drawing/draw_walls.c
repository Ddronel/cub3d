#include "../cub3d.h"

static int	shade_color(int color, double divide)
{
	if (divide <= 1.)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16) / divide) << 16)
			+ ((int)(((0x00FF00 & color) >> 8) / divide) << 8)
			+ ((int)((0x0000FF & color) / divide)));
}

static void	draw_wall_line(t_map *map, t_local *q, t_help_function *info,
							  int lineh)
{
	double	pix_start;
	double	pix_step;
	
	pix_step = 1. * info->wall_img.size_y / lineh / 2;
	pix_start = (q->starty - WIN_SIZE_Y / 2. + lineh) * pix_step;
	while (q->starty < q->endy)
	{
		q->startx = q->savex;
		pix_start += pix_step;
		if (info->side == 1 || info->side == 2)
			q->wall_clr = get_pixel(info->wall_img, info->x, pix_start);
		else
			q->wall_clr = get_pixel(info->wall_img, info->y, pix_start);
		q->wall_clr = shade_color(q->wall_clr, info->dist / 1.1);
		while (q->startx < q->endx)
			my_mlx_pixel_put(&map->img, q->startx++, q->starty, q->wall_clr);
		q->starty++;
	}
}

static void	draw_line_w(t_vars *param, int lineh, t_help_function info, int x)
{
	t_local	q;
	
	q.rad = 3000;
	q.starty = 400 - lineh;
	q.endy = 400 + lineh;
	q.savex = x * 2;
	q.endx = (x + 1) * 2;
	q.y = -1;
	if (q.starty < 0)
		q.starty = 0;
	if (q.endy > 800)
		q.endy = 800;
	draw_ceil(&q, &param->s_map->img, param->ceil_clr);
	draw_wall_line(param->s_map, &q, &info, lineh);
	draw_floor(&q, &param->s_map->img, param->floor_clr);
}

static void	ft_get_wall_info(t_vars *param, t_help_function *info, double dir)
{
	double	dist_on_y;
	double	dist_on_x;
	
//	printf("start\n");
	dist_on_y = cast_on_y(param->s_map, param->s_map->pers.pos_x, \
	param->s_map->pers.pos_y, dir);
//	dist_on_y = ft_find_horizontal_intersection(param->s_map, param->s_map->pers.pos_x, \
//	param->s_map->pers.pos_y, info->dir_start);
//	printf("start after horizont \n");
	cast_on_x(param->s_map, param->s_map->pers.pos_x, \
	param->s_map->pers.pos_y, dir);
//	dist_on_x = ft_find_vertical_intersection(param->s_map, param->s_map->pers.pos_x, \
//	param->s_map->pers.pos_y, info->dir_start);
//	printf("start after vert\n");
	if (dist_on_y > dist_on_x)
		get_ea_we_data(param, info, dist_on_x, dir);
	else
		get_no_so_data(param, info, dist_on_y, dir);
	info->y = fabs(sin(info->dir_start) * info->dist);
	info->x = fabs(cos(info->dir_start) * info->dist);
	calc_tex_dims(info, info->dir_start, param->s_map->pers.pos_x, \
		param->s_map->pers.pos_y);
}

void	ft_draw_walls(t_vars *param)
{
	t_help_function info;
	double			delta_dir;
	int				x;
	
	info.dir_end = param->s_map->pers.dir + FOV2;
	if (info.dir_end > PI * 2)
		info.dir_end -= PI * 2;
	info.dir_start = info.dir_end - 2 * FOV2;
	x = 659;
	while (info.dir_end > info.dir_start && x > -1)
	{
		delta_dir = param->s_map->pers.dir - info.dir_start;
		if (delta_dir < 0)
			delta_dir += 2 * PI;
		else if (delta_dir > 2 * PI)
			delta_dir -= 2 * PI;
		ft_get_wall_info(param, &info, info.dir_start);
		info.dist *= cos(delta_dir);
		draw_line_w(param, (int)(800 / info.dist / 2), info, x);
		info.dir_start += 0.00158666;
		x--;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->s_map->img.img, 0,
							0);
	
}