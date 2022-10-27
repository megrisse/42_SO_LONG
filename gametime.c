/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gametime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 01:31:54 by megrisse          #+#    #+#             */
/*   Updated: 2022/04/27 22:55:25 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	*player_position(char **map)
{
	t_pos	*pos;
	int		x;
	int		i;

	pos = malloc(sizeof(t_pos));
	i = 0;
	while (map[i])
	{
		x = 0;
		while (map[i][x])
		{
			if (map[i][x] == 'P')
			{
				pos->x = x;
				pos->y = i;
				return (pos);
			}
			x++;
		}
		i++;
	}
	return (NULL);
}

void	move_player(t_mlx *mlx)
{
	t_pos		*pos;
	t_inputs	input;

	input = mlx->player->input;
	pos = player_position(mlx->player->map);
	if (pos && !step_to_wall(mlx->player->map, pos, input))
	{
		steps_handler(mlx, pos, input);
	}
	if (pos)
		free (pos);
	reload_input(&mlx->player->input);
}

void	game_time(t_mlx *mlx)
{
	if (mlx->player->end == 1)
		return ;
	if (mlx->player->coins == 0 && mlx->player->col_bool == 0)
	{
		mlx->player->col_bool = 1;
		ft_printf("Door Unlocked\n");
	}
	move_player(mlx);
}

int	get_coins(char **map)
{
	int	coins;
	int	i;
	int	x;

	coins = 0;
	i = 0;
	while (map[i])
	{
		x = 0;
		while (map[i][x])
		{
			if (map[i][x] == 'C')
				coins++;
			x++;
		}
		i++;
	}
	return (coins);
}

void	init_player(t_mlx *mlx, char **map)
{
	mlx->player = malloc(sizeof(t_player));
	mlx->player->map = map;
	mlx->player->steps = 0;
	mlx->player->end = 0;
	mlx->player->collected = 0;
	mlx->player->col_bool = 0;
	mlx->player->coins = get_coins(mlx->player->map);
}
