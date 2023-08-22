/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_permutations.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabderra <nabderra@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:34:15 by nabderra          #+#    #+#             */
/*   Updated: 2023/08/22 10:35:04 by nabderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_PERMUTATIONS_H
#define BUILD_PERMUTATIONS_H

#include "rush.h"

void	perm_col(u8 *output, const u8 *input, u8 *permutation_vector, u8 size);

void	perm_row(u8 *output, const u8 *input, u8 *permutation_vector, u8 size);

u8		*build_permutations_matrix(u8 *permutation_vector, u8 size);

#endif
