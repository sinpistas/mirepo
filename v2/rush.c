/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabderra <nabderra@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:31:17 by nabderra          #+#    #+#             */
/*   Updated: 2023/08/22 10:31:38 by nabderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include "permutations.h"
#include "build_permutations.h"
#include "visible_boxes.h"

void	compute_bc_for_matrix(u8 *boundary_conditions, u8 *perm_matrix, u8 size)
{
	int	idx;
	u8	i;
	u8	*row;
	u8	col[SIZE];

	idx = 0;
	while (idx < size)
	{
		i = 0;
		while (i < size)
		{
			col[i] = perm_matrix[size * i + idx];
			++i;
		}
		boundary_conditions[idx] = visible_boxes_ltr(col, size);
		boundary_conditions[idx + size] = visible_boxes_rtl(col, size);
		row = &perm_matrix[idx * size];
		boundary_conditions[idx + size * 2] = visible_boxes_ltr(row, size);
		boundary_conditions[idx + size * 3] = visible_boxes_rtl(row, size);
		++idx;
	}
}

u8	*compute_boundary_conditions(u8 *permutation_matrix, u8 size)
{
	int	num_permutations;
	int	num_matrix;
	u8	*boundary_conditions;
	int	idx;

	num_permutations = factorial(size);
	num_matrix = num_permutations * num_permutations;
	boundary_conditions = malloc(num_matrix * 4 * size);
	idx = 0;
	while (idx < num_matrix)
	{
		compute_bc_for_matrix(&boundary_conditions[idx * 4 * size],
			&permutation_matrix[idx * size * size], size);
		++idx;
	}
	return (boundary_conditions);
}

int	compare_coeff(u8 *input_coeff, u8 *boundary_conditions, u8 size)
{
	int	idx;

	idx = 0;
	while (idx < size * 4)
	{
		if (input_coeff[idx] != boundary_conditions[idx])
			return (0);
		idx++;
	}
	return (1);
}

int	get_matrix_from_input(u8 *input_coeff, u8 *b_conditions, u8 size)
{
	int	idx;
	int	num_permutations;
	int	num_matrix;

	num_permutations = factorial(size);
	num_matrix = num_permutations * num_permutations;
	idx = 0;
	while (idx < num_matrix)
	{
		if (compare_coeff(input_coeff, &b_conditions[idx * 4 * size], size))
			break ;
		++idx;
	}
	if (idx == num_matrix)
		return (-1);
	return (idx);
}
