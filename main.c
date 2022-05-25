#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_draw_sq(t_map *map, int	x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i++ < 15)
	{
		j = 0;
		while (j++ < 15)
		{
			my_mlx_pixel_put(&map->img, x+i , y+j, color);
		}
	}
}

void	ft_draw_screen(t_vars *param)
{
	int		x;
	int		y;

	y = 0;
	while (param->s_map->map[y])
	{
		x = 0;
		while (param->s_map->map[y][x])
		{
			if (param->s_map->map[y][x] == '1')
				ft_draw_sq(param->s_map, x * 15, y * 15, 0xFFFFFFF);
			if (param->s_map->map[y][x] == 'N')
			{
				// printf("x %f\n", param->s_map->pers.pos_x);
				// printf("y %f\n",param->s_map->pers.pos_y);
				ft_draw_sq(param->s_map, x*15, y*15, 0x00FFFFF);
			}	
			x++;
		}
		y++;
	}							
	mlx_put_image_to_window(param->mlx, param->win, param->s_map->img.img, 0, 0);
}

int	ft_close(int keycode, t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->s_map->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int ft_buttons(int keycode, t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	if (keycode == 13) //w
	{
		if(vars->s_map->map[(int)vars->s_map->pers.pos_x - 1][(int)vars->s_map->pers.pos_y] == 0)
		{
			vars->s_map->map[(int)vars->s_map->pers.pos_x][(int)vars->s_map->pers.pos_y] = '0';
			vars->s_map->pers.pos_x -= 1.0;
			write(1, "w", 3);
			vars->s_map->map[(int)vars->s_map->pers.pos_x][(int)vars->s_map->pers.pos_y] = 'N';
		}
	}
	if (keycode == 0) //a
	{
		// vars->s_map->pers.pos_y += 1;
		vars->s_map->pers.pos_x -= 1;
	}
	if (keycode == 1) //s
	{
		vars->s_map->pers.pos_y -= 1;
	}
	if (keycode == 2) //d
	{
		// vars->s_map->pers.pos_y += 1;
		vars->s_map->pers.pos_x += 1;
	}
	ft_draw_screen(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	param;

	param.mlx = mlx_init();
	param.s_map = (t_map *)malloc(sizeof(t_map));
	ft_check_parse_file(argc, argv, &param);
	printf("%d\n%d\n", param.s_map->map_width,param.s_map->map_height);
	write(1, "ok\n", 3);
	ft_find_start_pos(param.s_map);
	param.win = mlx_new_window(param.mlx, 1320, 800, "cub3d");
	param.s_map->img.img = mlx_new_image(param.mlx, 640, 480);
	param.s_map->img.addr = mlx_get_data_addr(param.s_map->img.img, &param.s_map->img.bits_per_pixel, \
	&param.s_map->img.line_length, &param.s_map->img.endian);
	ft_draw_screen(&param);
	//mlx_hook(param.win, 2, 1L<<0, ft_close, &param);
	mlx_hook(param.win, 2, 1L<<0, &ft_buttons, &param);
	mlx_loop(param.mlx);
}
