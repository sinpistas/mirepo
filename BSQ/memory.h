/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:46:50 by apestana          #+#    #+#             */
/*   Updated: 2023/08/29 19:30:20 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H
# include "map.h"

int	destroy(t_map *s_map, int mode);

int	create(t_map *s_map);

int	generate(t_map *s_map, char *str, int size);

#endif