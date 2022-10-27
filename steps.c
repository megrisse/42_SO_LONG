/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 01:06:59 by megrisse          #+#    #+#             */
/*   Updated: 2022/04/22 01:07:01 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*          When your next move is wall textures handler         */

int     step_to_wall(char **map, t_pos *pos, t_inputs input)
{
    if (input.down && map[pos->y + 1][pos->x] == '1')
        return (1);
    else if (input.left && map[pos->y][pos->x - 1] == '1')
        return (1);
    else if (input.right && map[pos->y][pos->x + 1] == '1')
        return (1);
    else if (input.up && map[pos->y - 1][pos->x] == '1')
        return (1);
    return (0);   
}

/*          When your next move is door texture handler         */

int     step_to_door(char **map, t_pos *pos, t_inputs input)
{
    if (input.down && map[pos->y + 1][pos->x] == 'E')
        return (1);
    else if (input.left && map[pos->y][pos->x - 1] == 'E')
        return (1);
    else if (input.right && map[pos->y][pos->x + 1] == 'E')
        return (1);
    else if (input.up && map[pos->y - 1][pos->x] == 'E')
        return (1);
    return (0);      
}

/*          When your next move is coin textures handler         */

int     step_to_coin(char **map, t_pos *pos, t_inputs input)
{
    if (input.down && map[pos->y + 1][pos->x] == 'C')
        return (1);
    else if (input.left && map[pos->y][pos->x - 1] == 'C')
        return (1);
    else if (input.right && map[pos->y][pos->x + 1] == 'C')
        return (1);
    else if (input.up && map[pos->y - 1][pos->x] == 'C')
        return (1);
    return (0);   
}

/*                      after moving player textures handler                     */

int     after_move_player(char **map, t_pos *pos, t_inputs input)
{
    if (input.up)
        map[pos->y - 1][pos->x] = 'P';
    else if (input.right)
        map[pos->y][pos->x + 1] = 'P';
    else if (input.left)
        map[pos->y][pos->x - 1] = 'P';
    else if (input.down)
        map[pos->y + 1][pos->x] = 'P';
    else
        return (0);
    map[pos->y][pos->x] = '0';
    return (1);
}

/*                              moving player handler                               */

void    steps_handler(t_mlx *mlx, t_pos *pos, t_inputs input)
{
    if (step_to_door(mlx->player->map, pos, input))
    {
        if (mlx->player->coins <= 0)
        {
            mlx->player->map[pos->y][pos->x] = '0';    
            mlx->player->steps++;
            ft_printf("Steps : %d || ", mlx->player->steps);
			ft_printf("Collected : %d || ", mlx->player->collected);
			ft_printf("Coins Left : %d\n", mlx->player->coins);
            ft_printf("Congrats!!!!!!!!!!\n");
            mlx->player->end = 1;
            return ;
        }
    }
    else
    {
        if (check_input(input))
        {
            mlx->player->steps++;
            ft_printf("Steps : %d || ", mlx->player->steps);
			ft_printf("Collected : %d || ", mlx->player->collected);
			ft_printf("Coins Left : %d\n", mlx->player->coins);
        }
        if (step_to_coin(mlx->player->map, pos, input))
        {
            ft_printf("You Got a Coin\n");
            mlx->player->collected++;
            mlx->player->coins--;
        }
        after_move_player(mlx->player->map, pos, input);
    }
}