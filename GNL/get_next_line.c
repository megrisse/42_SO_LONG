/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:38:46 by megrisse          #+#    #+#             */
/*   Updated: 2022/01/05 22:23:18 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_read(int fd, char *buff, int i, char *rest)
// {
// 	char	*tmp;

// 	while (!ft_strchr(rest) && i != 0)
// 	{
// 		i = read(fd, buff, BUFFER_SIZE);
// 		if (i == -1)
// 		{
// 			free(buff);
// 			return (NULL);
// 		}
// 		buff[i] = '\0';
// 		tmp = rest;
// 		if (!tmp)
// 		{
// 			tmp = malloc(1 * sizeof(char));
// 			tmp[0] = '\0';
// 		}
// 		rest = ft_strjoin(tmp, buff);
// 		free(tmp);
// 	}
// 	free(buff);
// 	return (rest);
// }

// char	*ft_get_line(char *rest)
// {
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	if (!rest[i])
// 		return (NULL);
// 	while (rest[i] && rest[i] != '\n')
// 		i++;
// 	if (rest[i] == '\n')
// 		i++;
// 	line = malloc((i + 1) * sizeof(char));
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (rest[i] && rest[i - 1] != '\n')
// 	{
// 		line[i] = rest[i];
// 		i++;
// 	}
// 	line[i] = '\0';
// 	return (line);
// }

// char	*ft_after_nl(char *rest)
// {
// 	char	*new;
// 	int		i;
// 	int		x;

// 	i = 0;
// 	while (rest[i] && rest[i] != '\n')
// 		i++;
// 	if (!rest[i])
// 	{
// 		free(rest);
// 		return (NULL);
// 	}
// 	new = malloc((ft_strlen(rest) - i + 1) * sizeof(char));
// 	if (!new)
// 		return (NULL);
// 	i++;
// 	x = 0;
// 	while (rest[i])
// 		new[x++] = rest[i++];
// 	new[x] = '\0';
// 	free(rest);
// 	rest = NULL;
// 	return (new);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*rest;
// 	char		*buff;
// 	char		*line;
// 	int			i;

// 	if (fd < 0 || BUFFER_SIZE < 1)
// 		return (NULL);
// 	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buff)
// 		return (NULL);
// 	i = 1;
// 	rest = ft_read(fd, buff, i, rest);
// 	if (!rest)
// 		return (NULL);
// 	line = ft_get_line(rest);
// 	rest = ft_after_nl(rest);
// 	return (line);
// }

char	*get_save(char *save)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	rtn = malloc(sizeof(char) * ((xft_strlen(save) - i) + 1));
	if (!rtn)
		return (0);
	i++;
	while (save[i])
		rtn[j++] = save[i++];
	rtn[j] = '\0';
	free(save);
	return (rtn);
}

char	*get_line(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	rtn = malloc(sizeof(char) * (i + 1));
	if (!rtn)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int	get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*save;
	int				reader;

	reader = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !buff)
		return (-1);
	while (!has_return(save) && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reader] = '\0';
		save = join_str(save, buff);
	}
	free(buff);
	*line = get_line(save);
	save = get_save(save);
	if (reader == 0)
		return (0);
	return (1);
}