/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:38:46 by megrisse          #+#    #+#             */
/*   Updated: 2022/04/27 22:27:49 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_file(char **av)
{
	int		fd;
	char	*line;
	char	*temp;
	char	**map;

	fd = open(av[0], O_RDWR);
	if (fd == -1)
		ft_exit(1);
	temp = ft_strdup("");
	while (get_next_line(fd, &line))
	{
		temp = ft_strjoin(temp, line);
		temp = ft_strjoin(temp, ft_strdup("\n"));
	}
	temp = ft_strjoin(temp, line);
	return (temp);
}

void	check_elements_nbr(char *map)
{
	int			i;
	t_elements	el;

	el.c = 0;
	el.e = 0;
	el.p = 0;
	i = -1;
	while (map[++i])
	{
		if (map[i] == 'C')
			el.c++;
		if (map[i] == 'E')
			el.e++;
		if (map[i] == 'P')
			el.p++;
	}
	if (el.c < 1 || el.e < 1 || el.p != 1)
		ft_exit(2);
}

void	check_map_elements(char *str)
{
	int	i;
	int	x;

	i = -1;
	while (str[++i])
	{
		x = 0;
		if (str[i] != '0' && str[i] != '1' && str[i] != 'E'
			&& str[i] != 'C' && str[i] != 'P' && str[i] != '\n')
			ft_exit(2);
		if (str[i] == '\n')
		{
			if (x == 1)
				ft_exit(2);
			x = 1;
		}
		else
			x = 0;
	}
}

void	check_map_walls(char **map)
{
	int	i;
	int	x;
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		x = 0;
		while (map[i][x])
		{
			if (i == 0 && map[i][x] != '1')
				ft_exit(2);
			if (map[i + 1] == NULL && map[i][x] != '1')
				ft_exit(2);
			if (x == 0 && map[i][x] != '1')
				ft_exit(2);
			if (x == len - 1 && map[i][x] != '1')
				ft_exit(2);
			x++;
		}
		if (!map[i][x] && x != len)
			ft_exit(2);
		i++;
	}
}
