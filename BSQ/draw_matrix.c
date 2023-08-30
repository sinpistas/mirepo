/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:49:37 by vnaslund          #+#    #+#             */
/*   Updated: 2023/08/29 20:14:32 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "unistd.h"
#include "draw_matrix.h"

void	draw_matrix(t_map *s_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < s_map->rows)
	{
		j = 0;
		while (j < s_map->col)
		{
			write(1, &s_map->matrix_c[i][j], 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}

void	draw_matrix_int(t_map *s_map)
{
	int		i;
	int		j;
	char	conver;

	i = 0;
	while (i < s_map->rows)
	{
		j = 0;
		while (j < s_map->col)
		{
			conver = s_map->matrix_int[i][j] + '0';
			write(1, &conver, 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}