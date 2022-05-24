
#include "../cub3d.h"

void check_path_param(char **path)
{
    int fd;
    int i;
    char *str;

    i = 2;
    while ((*path)[i] == ' ')
        i++;
    fd = open(((*path) + i), O_RDONLY);
    if (fd == -1)
        ft_message_invalid_path(*path);
    else
    {
        str = ft_strdup((*path) + i);
        free(*path);
        *path = str;
    }
    close(fd);
}

char *after_comma(char *line){
    while (*line && *line != ',')
        line++;
    if (*line)
        line++;
    return line;
}

t_RGB *check_color_param(char *line)
{
    char    *saver;
    t_RGB   *ans;
    int     number;

    saver = line;
    ans = (t_RGB *)malloc(sizeof(t_RGB));
    saver++;
    number = ft_atoi(saver);
    if (number < 0 || number > 255)
        ft_message_invalid_RGB(line);
    ans->R = number;
    saver = after_comma(saver);
    number = ft_atoi(saver);
    if (number < 0 || number > 255)
        ft_message_invalid_RGB(line);
    ans->G = number;
    saver = after_comma(saver);
    number = ft_atoi(saver);
    if (number < 0 || number > 255)
        ft_message_invalid_RGB(line);
    ans->B = number;
    return (ans);
}
