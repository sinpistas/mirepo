/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:13:33 by apestana          #+#    #+#             */
/*   Updated: 2023/08/29 21:30:18 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "auxiliar.h"
#include "ft_atoi.h"
#include "memory.h"
#include <fcntl.h>
#include <sys/types.h>
//#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define N 1000000

int	second_check(t_map *s_map, char *str, int size)
{
	int	i;
	int	cont;
	int	can_be_solved;

	i = size + 4;
	can_be_solved = -1;
	cont = 0;
	while (str[i] !='\0')
	{
		if (str[i] == s_map->empty && can_be_solved == -1)
			can_be_solved = 1;
		if (str[i] == '\n' && cont == s_map->col)
			cont = -1;		
		else if (str[i] == '\n')
			return(-1); 	
		if (str[i] != s_map->obstacle && str[i] != s_map->empty && str[i] != '\n')
			return (-1);
		i++;
		cont++;
	}
	return (can_be_solved);
}

int	mount_matrix(t_map *s_map, char *str, int size)
{
	int	num;
	int	i;
	int	col;
	int	res;

	num = ft_atoi(str, size);
	s_map->rows = num;
	s_map->obstacle = str[size + 1];
	s_map->empty = str[size];
	s_map->full = str[size + 2];
	i = size + 4;
	col = 0;
	while (str[i] != '\n')
	{
		col++;
		i++;
	}
	s_map->col = col;
	if (second_check(s_map, str, size) == -1)
		return (-1); 
	res = generate(s_map, str, size);
	return (res);
}

int	firstline_check(char *str)
{
	int	i;
	int	ndig;

	i = 0;
	while (str[i] != '\n')
		i++;
	if (i < 4)
		return (-1);
	else if ((str[i - 1] == str[i - 2]) || (str[i - 1] == str[i - 3])
		|| (str[i - 3] == str[i - 2]))
		return (-1);
	i = i - 4;
	ndig = 0;
	while (i >= 0)
	{
		if ((str[i] > '9') || (str[i] < '0'))
			return (-1);
		i--;
		ndig++;
	}
	return (ndig);
}

int	read_file(char *str, char *src)
{
	char	c;
	int		len;
	int		bytes_read;
	int		fd;

	fd = open(src, O_RDONLY);
	if (fd < 0)
		return (-3);
	len = -1;
	bytes_read = read(fd, &c, 1);
	while (bytes_read > 0)
	{
		str[++len] = c;
		bytes_read = read(fd, &c, 1);
		if (len == N - 1)
			return (-3);
	}
	str[len] = '\0';
	close(fd);
	return (0);
}

int	read_keyboard(char *str)
{
	char	c;
	int		len;
	int		bytes_read;

	len = -1;
	bytes_read = read(0, &c, 1);
	if (bytes_read == 0)
		return (-3);
	while (bytes_read > 0)
	{
		str[++len] = c;
		bytes_read = read(0, &c, 1);
		if (len >= N - 1)
			return (-3);
	}
	str[len] = '\0';
	return (0);
}
