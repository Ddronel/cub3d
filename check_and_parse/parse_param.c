
#include "../cub3d.h"

static int check_letters(char ch)
{
    char str[7] = {'N', 'S', 'W', 'E', 'F', 'C', '\0'};
    int i;

    i = 0;
    while(str[i])
    {
        if (ch == str[i])
            return (1);
        i++;
    }
    if (ch == '\0')
        return (1);
    return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = -1;
	if (!s1 && !s2)
		return (0);
	else if (!s1 || !s2)
		return (1);
	while (s1[++i] || s2[i])
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (0);
} //TODO : убрать

static void	ft_load_image(char *str, t_vars *param, t_data *path)
{
	int	i;

	i = 0;
	while (str[i] != '/')
		i++;
	if (!ft_strcmp(str + ft_strlen(str) - 4, ".xpm"))
	{
		path->img = mlx_xpm_file_to_image(param->mlx, str + i, \
			&path->size_x, &path->size_y);
		if (!path->img)
			ft_message_invalid_path(str);
		path->addr = mlx_get_data_addr(path->img, &path->bits_per_pixel, \
		&path->line_length, &path->endian);
	}
	else
	{
		ft_message_invalid_path(str);
		free(param->str_params[0]);
		exit(1);
	}
}

static int	get_param_help(char *str, t_vars *param, int ans)
{
	param->str_params[0] = ft_strdup(str);
	check_path_param(&(param->str_params[0]));
	if (ans == 1)
		ft_load_image(str, param, &param->path_no);
	else if (ans == 2)
		ft_load_image(str, param, &param->path_so);
	else if (ans == 4)
		ft_load_image(str, param, &param->path_we);
	else if (ans == 8)
		ft_load_image(str, param, &param->path_ea);
	free(param->str_params[0]);
	return (ans);
}

int	get_param_and_load_image(char *str, t_vars *param)
{
	int	ans;

	ans = 0;
	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
		ans += get_param_help(str, param, 1);
	if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
		ans += get_param_help(str, param, 2);
	if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
		ans += get_param_help(str, param, 4);
	if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
		ans += get_param_help(str, param, 8);
	if (str[0] == 'F' && str[1] == ' ')
	{
		ans += 16;
		param->str_params[0] = ft_strdup(str + 2);
		param->RGB_F = check_color_param(param->str_params[0]);
	}
	if (str[0] == 'C' && str[1] == ' ')
	{
		ans += 32;
		param->str_params[1] = ft_strdup(str + 2);
		param->RGB_C = check_color_param(param->str_params[1]);
	}
	return (ans);
}

void	parse_param(int fd, t_vars *param)
{
	int		checksum;
	char	*str;

	checksum = 0;
	(param)->str_params = (char **)malloc(sizeof(char *) * 6);
	while (1)
	{
        str = get_next_line(fd);
		if (NULL == str || check_letters(str[0]) == 0 || checksum == 63)
			break ;
		if (str[0] != '\n')
		{
			checksum += get_param_and_load_image(str, param);
			free(str);
		}
	}
	if (checksum != 63)
	{
		write(1, "Incorrect params\n", 17);
		exit(-1);
	}
}