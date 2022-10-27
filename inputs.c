/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 03:22:51 by megrisse          #+#    #+#             */
/*   Updated: 2022/04/27 22:58:40 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pressed_keys(int key, t_mlx *mlx)
{
	int	pressed;

	pressed = mlx->player->input.pressed;
	if (key == ESC_KEY)
		ft_exit(4);
	else if (key == W_KEY && !pressed)
		mlx->player->input.up = 1;
	else if (key == A_KEY && !pressed)
		mlx->player->input.left = 1;
	else if (key == D_KEY && !pressed)
		mlx->player->input.right = 1;
	else if (key == S_KEY && !pressed)
		mlx->player->input.down = 1;
	else
		return (0);
	mlx->player->input.pressed = 1;
	return (1);
}

int	key_released(int key, t_mlx *mlx)
{
	if (key == W_KEY)
		mlx->player->input.up = 0;
	else if (key == A_KEY)
		mlx->player->input.left = 0;
	else if (key == D_KEY)
		mlx->player->input.right = 0;
	else if (key == S_KEY)
		mlx->player->input.down = 0;
	else
		return (0);
	mlx->player->input.pressed = 0;
	return (1);
}

int	check_input(t_inputs input)
{
	if (input.down || input.left || input.right || input.up)
		return (1);
	return (0);
}

void	get_input(t_mlx *mlx)
{
	mlx_hook(mlx->mlx_window, 2, 0, pressed_keys, mlx);
	mlx_hook(mlx->mlx_window, 3, 0, key_released, mlx);
	mlx_hook(mlx->mlx_window, 17, 0, ft_quit, mlx);
}

void	reload_input(t_inputs *input)
{
	input->down = 0;
	input->left = 0;
	input->right = 0;
	input->up = 0;
}
