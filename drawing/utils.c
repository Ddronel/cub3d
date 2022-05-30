#include "../cub3d.h"

int	get_pixel(t_data wall, double x, double y)
{
	int		*dst;
	int		color;
	
	dst = (void *)wall.addr + ((int )y * wall.line_length
							   + (int )x * (wall.bits_per_pixel / 8));
	color = *(int *)dst;
	return (color);
}

void	get_ea_we_data(t_vars *param, t_help_function *info, double dist,
					   double dir)
{
	if ((dir < 1.5 * PI && dir > PI2) || (dir < 3.5 * PI && dir > 2.5 * PI))
	{
		info->wall_img = param->path_we;
		info->side = 3;
	}
	else
	{
		info->wall_img = param->path_ea;
		info->side = 4;
	}
	info->dist = dist;
}

void	get_no_so_data(t_vars *param, t_help_function *info, double dist,
					   double dir)
{
	if ((dir < PI && dir > 0) || (dir < 3 * PI && dir > 2 * PI))
	{
		info->wall_img = param->path_no;
		info->side = 1;
	}
	else
	{
		info->wall_img = param->path_so;
		info->side = 2;
	}
	info->dist = dist;
}

void	calc_tex_dims(t_help_function *info, double dir, double persx, double
persy)
{
	if (dir < PI && dir > 0)
		info->y = -info->y;
	if (dir > PI2 && dir < PI2 * 3)
		info->x = -info->x;
	info->x += persx;
	info->y += persy;
	if ((dir < PI && dir > 0) || (dir < 3 * PI && dir > 2 * PI))
		info->x -= floor(info->x);
	else
		info->x = ceil(info->x) - info->x;
	if ((dir < 1.5 * PI && dir > PI2) || (dir < 3.5 * PI && dir > 2.5 * PI))
		info->y = ceil(info->y) - info->y;
	else
		info->y -= floor(info->y);
	info->x *= info->wall_img.size_x;
	info->y *= info->wall_img.size_x;
}
