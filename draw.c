/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 00:26:23 by megrisse          #+#    #+#             */
/*   Updated: 2022/04/26 17:09:10 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_resolution(char **map)
{
	int	i;

	i = 1;
	while (map[i++])
		g_map_height = i * MAPSIZE;
	g_map_width = (ft_strlen(map[1]) * MAPSIZE);
}

t_mlx	*ft_drawmap(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->mlx_window = mlx_new_window(mlx->mlx, g_map_width,
			g_map_height, "42_SO_LONG");
	mlx->mlx_img = mlx_new_image(mlx->mlx, g_map_width, g_map_height);
	mlx->mlx_addr = mlx_get_data_addr(mlx->mlx_img, &mlx->bpp,
			&mlx->sl, &mlx->endian);
	return (mlx);
}

void	fill_map(t_mlx	*mlx)
{
	int	w;
	int	h;

	mlx->texture.w.img = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Wall.xpm", &w, &h);
	mlx->texture.g.img = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Ground1.xpm", &w, &h);
	mlx->texture.c.img = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Coin2.xpm", &w, &h);
	mlx->texture.e.img = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Door3.xpm", &w, &h);
	mlx->texture.p.img = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Player2.xpm", &w, &h);
	mlx->texture.ee.img = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/Door4.xpm", &w, &h);
	check_textures(mlx, 0);
	mlx->texture.w.add = (unsigned int *)mlx_get_data_addr(mlx->texture.w.img,
			&mlx->texture.w.bpp, &mlx->texture.w.sl, &mlx->texture.w.end);
	mlx->texture.g.add = (unsigned int *)mlx_get_data_addr(mlx->texture.g.img,
			&mlx->texture.g.bpp, &mlx->texture.g.sl, &mlx->texture.g.end);
	mlx->texture.c.add = (unsigned int *)mlx_get_data_addr(mlx->texture.c.img,
			&mlx->texture.c.bpp, &mlx->texture.c.sl, &mlx->texture.c.end);
	mlx->texture.e.add = (unsigned int *)mlx_get_data_addr(mlx->texture.e.img,
			&mlx->texture.e.bpp, &mlx->texture.e.sl, &mlx->texture.e.end);
	mlx->texture.ee.add = (unsigned int *)mlx_get_data_addr(mlx->texture.ee.img,
			&mlx->texture.ee.bpp, &mlx->texture.ee.sl, &mlx->texture.ee.end);
	mlx->texture.p.add = (unsigned int *)mlx_get_data_addr(mlx->texture.p.img,
			&mlx->texture.p.bpp, &mlx->texture.p.sl, &mlx->texture.p.end);
}

void	my_mlx_pixel_put(t_mlx	*mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->mlx_addr + (y * mlx->sl + x * (mlx->bpp / 8));
	*(unsigned int *) dst = color;
}

void	rect(t_mlx *mlx, int x, int y, t_img texture)
{
	int	i;
	int	j;
	int	pos;

	i = y + 1;
	while (i < y + MAPSIZE)
	{
		j = x + 1;
		while (j < x + MAPSIZE)
		{
			pos = ((i - y) * MAPSIZE + (j - x));
			my_mlx_pixel_put(mlx, j, i, texture.add[pos]);
			j++;
		}
		i++;
	}
}
