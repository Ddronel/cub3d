//
// Created by Evelyn Veiled on 3/12/22.
//

#include "cub3d.h"

//void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//	char	*dst;
//
//	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int*)dst = color;
//}

void	ft_draw_screen(void)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = NULL;
	win = NULL;
	x = 100;
	y = 100;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "cub");
	while (y++ < 200)
	{
		x = 100;
		while (x++ < 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
		}
	}
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	t_vars	*param;

	param = (t_vars *)malloc(sizeof(t_vars));
	param->s_map = (t_map *)malloc(sizeof(t_map));
	ft_check_parse_file(argc, argv, param);
	//ft_draw_screen();
//    printf("---------------------------\n");
//    printf("%s\n", param->str_params[0]);
//    printf("%s\n", param->str_params[1]);
//    printf("%s\n", param->str_params[2]);
//    printf("%s\n", param->str_params[3]);
//    printf("-----\n");
//    printf("%s\n", param->str_params[4]);
//    printf("R: %d\n", param->RGB_F->R);
//    printf("G: %d\n", param->RGB_F->G);
//    printf("B: %d\n", param->RGB_F->B);
//    printf("-----\n");
//    printf("%s\n", param->str_params[5]);
//    printf("R: %d\n", param->RGB_C->R);
//    printf("G: %d\n", param->RGB_C->G);
//    printf("B: %d\n", param->RGB_C->B);
//    printf("-----\n");
//    int i = 0;
//    while(param->s_map->map[i])
//    {
//        printf("(%d) %s\n", i, param->s_map->map[i]);
//        i++;
//    }
//    printf("---------------------------\n");
//
//    return (0);
}
