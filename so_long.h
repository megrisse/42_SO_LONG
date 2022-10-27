/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 03:27:31 by megrisse          #+#    #+#             */
/*   Updated: 2022/03/24 03:27:35 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <sys/time.h>
# include <signal.h>
# include <string.h> 
# include "./GNL/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "./Libft/libft.h"

# define W 1080
# define H 720

# define A_KEY 0
# define D_KEY 2
# define S_KEY 1
# define W_KEY 13
# define ESC_KEY 53

# define MAPSIZE 64

# define RED_PIXEL 0xFF0000
# define BLUE_PIXEL 0x000000FF

typedef struct s_elements
{
    int p;
    int c;
    int e;
}       t_elements;

typedef struct s_positions
{
    int x;
    int y;
}           t_positions;

int g_map_height;
int g_map_width;

int g_x;
int g_y;

typedef struct s_inputs
{
    int pressed;
    int up;
    int down;
    int left;
    int right;
}           t_inputs;

typedef struct s_img
{
    void             *img;
    unsigned int     *add;
    int              bpp;
    int              sl;
    int              end;
}               t_img;

typedef struct s_player
{
    t_inputs    input;
    int         steps;
    int         coins;
    int         end;
    int         col_bool;
    int         collected;
    char        **map;
}           t_player;

typedef struct s_textures
{
    t_img   p;
    t_img   c;
    t_img   e;
    t_img   w;
    t_img   g;
    t_img   ee;
}           t_textures;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_mlx
{
    void		*mlx;
	void		*mlx_window;
	void		*mlx_img;
	char		*mlx_addr;
	int			bpp;
	int			sl;
	int			endian;
	t_player	*player;
	t_textures	texture;
	char		**av;
}           t_mlx;

void    check_elements_nbr(char *str);
char    *ft_file(char **av);
char    **check_map_finish(char **av);
int     ft_exit(int x);

void    my_mlx_pixel_put(t_mlx  *data, int x, int y, int color);
void    finish_drawing_map(t_mlx *mlx, char **map);
void    check_textures(t_mlx *mlx, int code);
void	rect(t_mlx *mlx, int x, int y, t_img texture);
void    draw(t_mlx *mlx, char   **map);
void    check_exit(int w, int h);

void    check_map_elements(char *str);
void    init_el(t_elements *el);
void    init_player(t_mlx *mlx, char **map);
void    fill_map(t_mlx  *mlx);
void    check_map_walls(char **map);
void    ft_resolution(char **map);

int     after_move_player(char **map, t_pos *pos, t_inputs input);
int     step_to_coin(char **map, t_pos *pos, t_inputs input);
int     step_to_wall(char **map, t_pos *pos, t_inputs input);
void    steps_handler(t_mlx *mlx, t_pos *pos, t_inputs input);

void    get_input(t_mlx *mlx);
int     check_input(t_inputs input);
int     ft_quit(void);
void    reload_input(t_inputs *input);
int     render(t_mlx *mlx);
int     refresh(t_mlx *mlx);
void    load_next(t_mlx *mlx);

void    game_time(t_mlx *mlx);
int     game_hook(void *mlx);


t_mlx    *ft_drawmap(void);

#endif