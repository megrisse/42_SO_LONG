/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:49:45 by megrisse          #+#    #+#             */
/*   Updated: 2022/03/31 20:49:55 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    draw(t_mlx *mlx, char   **map)
{
    int i;
    int x;

    i = 0;

    while (map[i])
    {
        x = 0;
        while (map[i][x])
        {
            if (map[i][x] == '1')
                rect(mlx, x * MAPSIZE, i * MAPSIZE, mlx->texture.g);
            else if (map[i][x] == '0')
                rect(mlx, x * MAPSIZE, i *  MAPSIZE, mlx->texture.w);
            x++;
        }
        i++;
    }
}

void    finish_drawing_map(t_mlx *mlx, char **map)
{
    int i;
    int x;

    i = 0;
    while(map[i])
    {
        x = 0;
        while (map[i][x])
        {
            if (map[i][x] == '1')
                rect(mlx, x * MAPSIZE, i * MAPSIZE, mlx->texture.w);
            if (map[i][x] == 'C')
                rect(mlx, x * MAPSIZE, i * MAPSIZE, mlx->texture.c);
            else if (map[i][x] == 'P')
                rect(mlx, x * MAPSIZE, i * MAPSIZE, mlx->texture.p);
            else if (map[i][x] == '0')
                rect(mlx, x * MAPSIZE, i * MAPSIZE, mlx->texture.g);
            else if (map[i][x] == 'E')
                //check_exit(x, i);
                rect(mlx, x * MAPSIZE, i * MAPSIZE, mlx->texture.e);
            x++;
        }
        i++;
    }
}

int game_hook(void *mlx)
{
    refresh((t_mlx *)mlx);
    get_input((t_mlx *)mlx);
    game_time((t_mlx *)mlx);
    render((t_mlx *)mlx);
    load_next(mlx);
    return (0);
}

int check_ber(char  *str)
{
    int		i;
	char	*find;
	int		x;

	i = 0;
	find = ".ber";
	x = -1;
	while (str[i])
	{
		x = -1;
		while (str[i] == find[++x])
		{
			if (!find[x + 1])
				return (1);
			i++;
		}
		i++;
	}
	ft_printf("map must be .ber\n");
	exit(0);
}

int main(int ac, char **av)
{
    t_mlx   *mlx;
    char    **map;

    if (ac != 2)
        ft_exit(0);
    check_ber(av[1]);
    map = check_map_finish(av + 1);
    ft_resolution(map);
    mlx = ft_drawmap();
    mlx->av = av;
    fill_map(mlx);
    check_textures(mlx, 1);
    finish_drawing_map(mlx, map);
    mlx_put_image_to_window(mlx, mlx->mlx_window, mlx->mlx_img, 0, 0);
    check_textures(mlx, 1);
    init_player(mlx, map);
    mlx_loop_hook(mlx->mlx, game_hook, mlx);
    mlx_loop(mlx);
}