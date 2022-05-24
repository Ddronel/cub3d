
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

int get_param(char *str, t_vars *param)
{
    int ans;

    ans = 0;
    if (str[0] == 'N' && str[1] == 'O' && str[2] == ' '){
        ans += 1;
        param->str_params[0] = ft_strdup(str);
        check_path_param(&(param->str_params[0]));
    }
    if (str[0] == 'S' && str[1] == 'O' && str[2] == ' '){
        ans += 2;
        param->str_params[1] = ft_strdup(str);
        check_path_param(&(param->str_params[1]));
    }
    if (str[0] == 'W' && str[1] == 'E' && str[2] == ' '){
        ans += 4;
        param->str_params[2] = ft_strdup(str);
        check_path_param(&(param->str_params[2]));
    }
    if (str[0] == 'E' && str[1] == 'A' && str[2] == ' '){
        ans += 8;
        param->str_params[3] = ft_strdup(str);
        check_path_param(&(param->str_params[3]));
    }
    if (str[0] == 'F' && str[1] == ' '){
        ans += 16;
        param->str_params[4] = ft_strdup(str);
        param->RGB_F = check_color_param(param->str_params[4]);
    }
    if (str[0] == 'C' && str[1] == ' '){
        ans += 32;
        param->str_params[5] = ft_strdup(str);
        param->RGB_C = check_color_param(param->str_params[5]);
    }
    return (ans);
}

void	parse_param(int fd,t_vars *param)
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
            checksum += get_param(str, param);
            free(str);
        }
    }
    if (checksum != 63){
        write(1, "Incorrect params\n", 17);
        exit(-1);
    }
}