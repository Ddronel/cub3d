#ifndef CUB3D_CUB3D_H
# define CUB3D_CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"

# define PI 3.14159265
# define PI2 1.57079632


/*structures*/

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		size_x;
	int		size_y;
}	t_data;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_RGB
{
    int     R;
    int     G;
    int     B;
}	t_RGB;

typedef struct s_pers
{
	double	dir;
	double	pos_x;
	double	pos_y;
}	t_pers;

typedef struct s_map
{
	t_data	img;
	char	**map;
	int		map_width;
	int		map_height;
	t_pers	pers;
	t_keys	keys;
}	t_map;

typedef struct s_vars
{
    void	*mlx;
    void	*win;
    char	**str_params;
	t_data	path_no;
	t_data	path_so;
	t_data	path_we;
	t_data	path_ea;
//    void	**ptrs;
    t_map	*s_map;
    t_RGB	*RGB_F;
    t_RGB	*RGB_C;
}	t_vars;

/*messages*/
void	ft_message_cant_open(void);
void	ft_message_invalid_map(void);
void	ft_message_where_is_map(void);
void	ft_message_invalid_path(char *path);
void    ft_message_invalid_RGB(char *line);

/*functions*/
void	ft_check_parse_file(int argc, char **argv, t_vars	*param);
t_RGB *check_color_param(char *line);
void	parse_param(int fd,t_vars *param);
t_RGB   *check_color_param(char *line);
void    check_path_param(char **path);
void    check_map(t_vars *param);
char    **parse_map(int fd);

/*libft's func*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
int	    ft_atoi(const char *str);

//main.c
int	ft_close(t_vars *vars);


//record_start_pos.c
void ft_find_start_pos(t_map *s_map);

#endif
