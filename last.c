/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 00:26:50 by megrisse          #+#    #+#             */
/*   Updated: 2022/04/27 23:16:06 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	refresh(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->mlx_img);
	mlx->mlx_img = mlx_new_image(mlx->mlx, g_map_width, g_map_height);
	mlx->mlx_addr = mlx_get_data_addr(mlx->mlx_img,
			&mlx->bpp, &mlx->sl, &mlx->endian);
	return (0);
}

void	check_exit(int w, int h)
{
	t_mlx	*mlx;

	if (mlx->player->coins != 0)
		rect(mlx, w * MAPSIZE, h * MAPSIZE, mlx->texture.e);
	if (mlx->player->coins == 0)
		rect(mlx, w * MAPSIZE, h * MAPSIZE, mlx->texture.ee);
}

void	load_next(t_mlx *mlx)
{
	char		**map;
	static int	x;

	x = 1;
	if (mlx->player->end == 1)
	{
		if (mlx->av[x + 1] != NULL)
			x++;
		else
			x = 1;
		map = check_map_finish(mlx->av + x);
		fill_map(mlx);
		check_textures(mlx, 1);
		init_player(mlx, map);
	}
	else
		return ;
}

int	mouse_test(int key, int x, int y)
{
	g_y = y;
	g_x = x;
	key = 0;
	return (0);
}

int	render(t_mlx *mlx)
{
	draw(mlx, mlx->player->map);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->mlx_img, 0, 0);
	finish_drawing_map(mlx, mlx->player->map);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->mlx_img, 0, 0);
	char *collected = malloc(sizeof(char) * 100);
	char *steps = malloc(sizeof(char) * 100);
	char *remains = malloc(sizeof(char) * 100);

	char *x_position = malloc(sizeof(char) * 100);
	char *y_position = malloc(sizeof(char) * 100);
	mlx_mouse_hook(mlx->mlx_window, mouse_test, NULL);
	int x = g_x;
	int y = g_y;
	sprintf(x_position, "%d", x);
	sprintf(y_position, "%d", y);

	x_position = ft_strjoin(ft_strdup("x pos : "), x_position);
	y_position = ft_strjoin(ft_strdup("y pos : "), y_position);
	mlx_string_put(mlx->mlx, mlx->mlx_window, (g_map_width / 2) + (g_map_width / 4), 10, 0x00FFFFFF , x_position);
	mlx_string_put(mlx->mlx, mlx->mlx_window, (g_map_width / 2) + (g_map_width / 4), 30, 0x00FFFFFF , y_position);
	
	sprintf(collected, "%d", mlx->player->collected);
	collected = ft_strjoin(ft_strdup("collected : "), collected);
	sprintf(steps, "%d", mlx->player->steps);
	steps = ft_strjoin(ft_strdup("steps : "), steps);
	sprintf(remains, "%d", mlx->player->coins);
	remains = ft_strjoin(ft_strdup("coins remaining : "), remains);
	mlx_string_put(mlx->mlx, mlx->mlx_window, 10, 20, 0x00FFFFFF , steps);
	mlx_string_put(mlx->mlx, mlx->mlx_window, 130, 20, 0x00FFFFFF , collected);
	mlx_string_put(mlx->mlx, mlx->mlx_window, 330, 20, 0x00FFFFFF , remains);
    
	if (mlx->player->coins == 0 && mlx->player->end == 0)
		mlx_string_put(mlx->mlx, mlx->mlx_window, g_map_width / 2, 20, 0x00FFFFFF , "Door Unlocked");
	if (mlx->player->end == 1)
		mlx_string_put(mlx->mlx, mlx->mlx_window, g_map_width / 2, g_map_height / 2, 0x00FFFFFF , "Congrats !!!!!");
	return (0);
}
