#include "cub3d.h"

int	ft_close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void ft_buttons()
// {

// }

// void	ft_draw_palyer(t_map *s_map)
// {
// 	ft_find_start_pos(s_map);
// 	while ()
// }

// void	ft_draw_screen(void)
// {
// 	void	*mlx;
// 	void	*win;
// 	int		x;
// 	int		y;
// 	int i = 0;

// 	mlx = NULL;
// 	win = NULL;
// 	x = 100;
// 	y = 100;
// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 640, 480, "cub");
// 	while (i < 240)
// 	{
// 		x = 100;
// 		while (x++ < 200)
// 		{
// 			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
// 		}
// 		i++;
// 	}
// 	mlx_loop(mlx);
// }

// int	main(int argc, char **argv)
// {
// 	t_vars	*param;

// 	param = (t_vars *)malloc(sizeof(t_vars));
// 	param->s_map = (t_map *)malloc(sizeof(t_map));
// 	ft_check_parse_file(argc, argv, param);
// 	ft_draw_screen(param->s_map);

//    return (0);
// }


int	main(int argc, char **argv)
{
	// void	*mlx;
	// void	*mlx_win;
	t_data	img;
	t_vars	*param;
	int		x;
	int		y;

	x = 0;
	y = 0;
	param = (t_vars *)malloc(sizeof(t_vars));
	param->s_map = (t_map *)malloc(sizeof(t_map));
	param->s_map->pers = (t_pers *)malloc(sizeof(t_pers));
	ft_check_parse_file(argc, argv, param);
	write(1, "ok\n", 3);
	ft_find_start_pos(param->s_map);
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, 640, 480, "Hello world!");
	img.img = mlx_new_image(param->mlx, 640, 480);
	img.line_length = 10;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (y++ < 5)
	{
		x = 0;
		while (x++ < 5)
		{
			my_mlx_pixel_put(&img, x, y, 0xFFFFFFF);
		}
	}							
	// my_mlx_pixel_put(&img, 5, 5, 0xFFFFFFF);
	mlx_put_image_to_window(param->mlx, param->win, img.img, param->s_map->pers->pos_x, param->s_map->pers->pos_y);
	mlx_hook(param->win, 2, 1L<<0, ft_close, param);
	mlx_loop(param->mlx);
}