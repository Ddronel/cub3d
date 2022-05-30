#include "../cub3d.h"

int	add_transparency(int color, double divide)
{
	int	transparency;
	
	transparency = 0x11000000;
	return ((((int)((transparency >> 24) * divide)) << 24) + color);
}

void	draw_floor(t_local *q, t_data *background, int color)
{
	q->endy = 800;
	q->rad += 800;
	while (q->starty < q->endy--)
	{
		q->startx = q->savex;
		q->res = sqrt((q->endy - q->rad) * (q->endy - q->rad)
					  + (q->startx - 660) * (q->startx - 660));
		q->floor_clr = color;
		if (800 - q->rad + q->res > 345)
			q->floor_clr = 0xFF000000;
		else
			q->floor_clr = add_transparency(color,
											(800 - q->rad + q->res) / 23.);
		while (q->startx < q->endx)
			my_mlx_pixel_put(background, q->startx++, q->endy, q->floor_clr);
	}
}

void	draw_ceil(t_local *q, t_data *background, int color)
{
	while (++q->y < q->starty)
	{
		q->startx = q->savex;
		q->res = (int )sqrt((q->y + q->rad) * (q->y + q->rad)
							+ (q->startx - 660) * (q->startx - 660));
		q->ceil_clr = color;
		if (q->res - q->rad > 345)
			q->ceil_clr = 0xFF000000;
		else
			q->ceil_clr = add_transparency(color, (q->res - q->rad) / 23.);
		while (q->startx < q->endx)
			my_mlx_pixel_put(background, q->startx++, q->y, q->ceil_clr);
	}
}
