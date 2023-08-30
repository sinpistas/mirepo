/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:48:23 by apestana          #+#    #+#             */
/*   Updated: 2023/08/29 21:19:04 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "map.h"
#include <stdlib.h>

int	destroy(t_map *s_map, int mode)
{
	int	j;

	j = 0;
	if (mode != -1)
	{
		while (j < s_map->rows)
		{
			free(s_map->matrix_c[j]);
			free(s_map->matrix_int[j]);
			j++;
		}
	}
	free(s_map->matrix_c);
	free(s_map->matrix_int);
	return (mode);
}

int	create(t_map *s_map)
{
	int	j;

	j = -1;
	s_map->matrix_c = (char **)malloc((s_map->rows) * sizeof(char *));
	s_map->matrix_int = (int **)malloc((s_map->rows) * sizeof(int *));
	if (s_map->matrix_c == NULL || s_map->matrix_int == NULL)
		return (destroy(s_map, -1));
	while (++j < s_map->rows)
	{
		s_map->matrix_c[j] = (char *)malloc((s_map->col) * sizeof(char));
		s_map->matrix_int[j] = (int *)malloc((s_map->col) * sizeof(int));
		if (s_map->matrix_c[j] == NULL || s_map->matrix_int[j] == NULL )
			return (destroy(s_map, -2));
	}
	return (0);
}

int	generate(t_map *s_map, char *str, int size)
{
	int	k;
	int	i;
	int	j;

	if (create(s_map) != 0)
		return (-1);
	k = size + 3;
	i = -1;
	while (++i < s_map->rows)
	{
		j = -1;
		while (++j < s_map->col)
		{
			if (str[k] == '\n')
				k++;
			if (str[k] != '\0' && (str[k] == s_map->obstacle
					|| str[k] == s_map->empty))
				s_map->matrix_c[i][j] = str[k];
			else
				return (destroy(s_map, -2));
			k++;
		}
	}
	return (0);
}
