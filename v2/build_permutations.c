/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_permutations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabderra <nabderra@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:34:04 by nabderra          #+#    #+#             */
/*   Updated: 2023/08/22 10:34:08 by nabderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"
#include "permutations.h"

static const u8	g_initial_matrix[] = {1, 2, 3, 4, 2, 3, 4, 1, 3, 4, 1, 2, 4, 1,
	2, 3};

void	perm_col(u8 *output, const u8 *input, u8 *permutation_vector, u8 size)
{
	u8	i;
	u8	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			output[size * i + j] = input[size * i + permutation_vector[j] - 1];
			++j;
		}
		++i;
	}
}

void	perm_row(u8 *out, const u8 *input, u8 *permutation_vector, u8 size)
{
	u8	i;
	u8	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			out[size * i + j] = input[size * (permutation_vector[i] - 1) + j];
			++j;
		}
		++i;
	}
}

static u8	*alloc_all_matrix(u8 size)
{
	int	num_matrix;
	int	num_permutations;
	u8	*all_matrix;

	num_permutations = factorial(size);
	num_matrix = num_permutations * num_permutations;
	all_matrix = malloc(num_matrix * size * size);
	return (all_matrix);
}

u8	*build_permutations_matrix(u8 *perm_vector, u8 size)
{
	int	i;
	int	j;
	int	num_permutations;
	u8	*all_matrix;
	u8	aux_mat[SIZE * SIZE];

	num_permutations = factorial(size);
	all_matrix = alloc_all_matrix(size);
	i = 0;
	while (i < num_permutations)
	{
		perm_col(aux_mat, g_initial_matrix, &perm_vector[size * i], size);
		j = 0;
		while (j < num_permutations)
		{
			perm_row(&all_matrix[(i * num_permutations + j) * size * size],
				aux_mat, &perm_vector[size * j], size);
			++j;
		}
		++i;
	}
	return (all_matrix);
}
