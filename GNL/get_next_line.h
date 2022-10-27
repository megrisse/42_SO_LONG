/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:42:04 by megrisse          #+#    #+#             */
/*   Updated: 2021/12/19 21:37:37 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef GET_NEXT_LINE_H
// # define GET_NEXT_LINE_H

// # include <unistd.h>
// # include <stdlib.h>
// # include <fcntl.h>
// # include <stdio.h>
// # define BUFFER_SIZE 100

// size_t	ft_strlen(const char *s);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strchr(const char *s);
// char	*get_next_line(int fd);

// #endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 100

int					get_next_line(int fd, char **line);
int					has_return(char *str);

size_t				xft_strlen(const char *s);

char				*join_str(const char *s1, const char *s2);

#endif