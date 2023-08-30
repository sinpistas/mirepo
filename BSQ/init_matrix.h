/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:10:10 by vnaslund          #+#    #+#             */
/*   Updated: 2023/08/29 18:37:48 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MATRIX_H
# define INIT_MATRIX_H
# include "map.h"

void	init_matrix(t_map *s_map);

void	solution(t_map *s_map);

int		calc(int x, int y, int z);

int		find_max(t_map *s_map, int *x, int *y);

void	fill_square(t_map *s_map, int x, int y, int size);

#endif
