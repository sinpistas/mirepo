/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabderra <nabderra@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:19:35 by nabderra          #+#    #+#             */
/*   Updated: 2023/08/22 10:21:49 by nabderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H
#include <stdlib.h>
#include "rush.h"

void	swap(u8 *a, u8 *b);

void	permutation(u8 *arr, struct s_pair p, u8 *all_rows, int *all_rows_idx);

u8		factorial(u8 size);

u8		*build_permutations_vector(u8 size);

#endif
