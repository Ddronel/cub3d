
#include "../cub3d.h"

char	**ft_increase_ArrayList(char ***map, int *map_size)
{
	char	**new_map;
	int		i;

    i = 0;
    new_map = (char **)malloc(sizeof(char *) * (*map_size * 2));
	while (i < *map_size)
	{
		new_map[i] = (*map)[i];
		i++;
	}
	free(*map);
    *map_size *= 2;
	return (new_map);
}

char	**parse_map(int fd)
{
	int		map_size;
	char	*str;
	char	**map;
	int		i;
	int		j;

	map_size = 10;
	map = (char **)malloc(sizeof(char *) * map_size);
//    if (!map)
//    {
//        ft_incorrect_malloc();
//    }
	str = get_next_line(fd);
	while (NULL != str && str[0] != ' ' && str[0] != '1')
	{
		free(str);
        str = get_next_line(fd);
    }
	printf("GNL str %s\n", str);
    i = 0;
	while (1)
	{
		if (i == map_size)
		{
			write(1, "load\n", 5);
            map = ft_increase_ArrayList(&map, &map_size);
			j = 0;
			while (map[j])
				j++;
		}
		map[i++] = str;
		str = get_next_line(fd);
		if (NULL == str || ft_strlen(str) == 0)
			break ;
	}
	return (map);
}

static int	check_letters(char ch)
{
	char	str[5] = {'0', 'W', 'S', 'E', 'N'};
	int		i;

	i = 0;
	while (i < 5)
	{
		if (ch == str[i])
			return (1);
		i++;
	}
	return (0);
}

void	check_map(t_vars *param)
{
	int	i;
	int	j;

	param->s_map->map_height = 0;
	while (param->s_map->map[param->s_map->map_height])
		param->s_map->map_height++;
	i = -1;
	while (++i < param->s_map->map_height)
	{
		j = -1;
		param->s_map->map_width = ft_strlen(param->s_map->map[i]);
		while (++j < param->s_map->map_width)
		{
			if (check_letters(param->s_map->map[i][j]))
			{
				if (i == 0 || i + 1 == param->s_map->map_height || \
				j == 0 || j + 1 == param->s_map->map_width \
				|| param->s_map->map[i - 1][j] == ' ' || \
				param->s_map->map[i + 1][j] == ' ' \
				|| param->s_map->map[i][j + 1] == ' ' || \
				param->s_map->map[i][j - 1] == ' ')
					ft_message_invalid_map();
			}
		}
	}
}
