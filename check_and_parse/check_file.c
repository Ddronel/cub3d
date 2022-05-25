
#include "../cub3d.h"

void check_filename(char *filename)
{
    char **splitted_filename;
    int size;

    size = 0;
    splitted_filename = ft_split(filename, '.');
    while (splitted_filename[size] != NULL)
        size++;
    if (size < 2 || ft_strncmp(splitted_filename[size - 1], "cub", 4) != 0){
        write(1, "Invalid filename.\n", 18);
        exit(-1);
    }
    size = 0;
    while (splitted_filename[size])
        free(splitted_filename[size++]);
    free(splitted_filename);
}

void	ft_check_parse_file(int argc, char **argv, t_vars *param)
{
    int		fd;

    if (argc != 2)
        ft_message_where_is_map();
    check_filename(argv[1]);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1){
        ft_message_cant_open();
    }
    parse_param(fd, param);
    param->s_map->map = parse_map(fd);
    check_map(param);
    close(fd);
}
