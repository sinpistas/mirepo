/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:29:43 by vnaslund          #+#    #+#             */
/*   Updated: 2023/08/29 20:45:01 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_matrix.h"

void	init_matrix(t_map *s_map)
{
	int	i;
	int	j;
	int	max;
	int	x;
	int	y;

	i = -1;
	x = 0;
	y = 0;
	while (++i < s_map->rows)
	{
		j = -1;
		while (++j < s_map->col)
		{
			if (s_map->matrix_c[i][j] == s_map->obstacle)
				s_map->matrix_int[i][j] = 0;
			else if (s_map->matrix_c[i][j] == s_map->empty)
				s_map->matrix_int[i][j] = -1;
		}
	}
	solution(s_map);
	max = find_max (s_map, &x, &y);
	fill_square(s_map, x, y, max);
}

void	solution(t_map *s_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < s_map->rows)
	{
		j = 0;
		while (j < s_map->col)
		{
			if ((j == 0 || i == 0) && s_map->matrix_int[i][j] != 0)
				s_map->matrix_int[i][j] = 1;
			else if (s_map->matrix_int[i][j] != 0)
				s_map->matrix_int[i][j] = calc(s_map->matrix_int[i - 1][j],
						s_map->matrix_int[i][j - 1],
						s_map->matrix_int[i - 1][j - 1]);
			++j;
		}
		++i;
	}
}

int	calc(int x, int y, int z)
{
	int	min_val;

	min_val = x;
	if (y < min_val)
		min_val = y;
	if (z < min_val)
		min_val = z;
	return (min_val + 1);
}

int	find_max(t_map *s_map, int *x, int *y)
{
	int	i;
	int	j;
	int	max;

	max = 0;
	i = 0;
	while (i < s_map->rows)
	{
		j = 0;
		while (j < s_map->col)
		{
			if (s_map->matrix_int[i][j] > max)
			{
				max = s_map->matrix_int[i][j];
				*x = i;
				*y = j;
			}
			++j;
		}
		++i;
	}
	return (max);
}

void	fill_square(t_map *s_map, int x, int y, int size)
{
	int	i;
	int	j;
	int	c;
	int	r;

	r = 0;
	i = x;
	while (r < size)
	{
		c = 0;
		j = y;
		while (c < size)
		{
			s_map->matrix_c[i][j] = s_map->full;
			--j;
			++c;
		}
		--i;
		++r;
	}
}
