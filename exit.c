/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:44:11 by megrisse          #+#    #+#             */
/*   Updated: 2022/04/27 22:50:31 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(int x)
{
	if (x == 0)
		ft_printf("Arguments Error\n");
	if (x == 1)
		ft_printf("File Error\n");
	if (x == 2)
		ft_printf("Map Error\n");
	if (x == 3)
		ft_printf("Texture Error\n");
	if (x == 4)
		ft_printf("YOU EXISTED THE GAME \n");
	exit(0);
	return (0);
}

int	ft_quit(void)
{
	exit(0);
	return (0);
}

char	**check_map_finish(char **av)
{
	char	*str;
	char	**map;

	str = ft_file(av);
	check_map_elements(str);
	check_elements_nbr(str);
	map = ft_split(str, '\n');
	free (str);
	check_map_walls(map);
	return (map);
}

void	check_textures(t_mlx *mlx, int code)
{
	if (code == 0)
	{
		if (!mlx->texture.c.img || !mlx->texture.e.img || !mlx->texture.g.img
			|| !mlx->texture.p.img || !mlx->texture.w.img
			|| !mlx->texture.ee.img)
			ft_exit(3);
	}
	if (code == 1)
	{
		if (!mlx->texture.c.add || !mlx->texture.e.add || !mlx->texture.g.add
			|| !mlx->texture.p.add || !mlx->texture.w.add
			|| !mlx->texture.ee.add)
			ft_exit(3);
	}
}
