/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:06:06 by apestana          #+#    #+#             */
/*   Updated: 2023/08/29 18:49:35 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_struct
{
	int		rows;
	int		col;
	char	obstacle;
	char	empty;
	char	full;
	char	**matrix_c;
	int		**matrix_int;

}	t_map;

int	second_check(t_map *s_map, char *str, int size);

int	mount_matrix(t_map *s_map, char *str, int size);

int	firstline_check(char *str);

int	read_file(char *str, char *src);

int	read_keyboard(char *str);

#endif