/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabderra <nabderra@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:34:38 by nabderra          #+#    #+#             */
/*   Updated: 2023/08/22 10:34:39 by nabderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "rush.h"
#include "permutations.h"
#include "build_permutations.h"
#include "check_string.h"
#include <stdio.h>

void	print_result(int idx, u8 size, u8 *permutation_matrix)
{
	u8	i;
	u8	j;

	if (idx == -1)
	{
		write(1, "Error!\n", 6);
		return ;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			printf("%d ", permutation_matrix[size * size * idx + size * i + j]);
			++j;
		}
		printf("\n");
		++i;
	}
}

int	main(int argc, char *argv[])
{
	u8	size;
	u8	*permutations;
	u8	*boundary_conditions;
	u8	input_coeff[SIZE * 4];
	int	idx;

	if (argc != 2)
		write(1, "Error\n", 6);
	else if (check_string(argv[1]) == -1)
		write(1, "Error\n", 6);
	else
	{
		size = SIZE;
		permutations = build_permutations_vector(size);
		permutations = build_permutations_matrix(permutations, size);
		boundary_conditions = compute_boundary_conditions(permutations, size);
		input_initializer(input_coeff, argv[1], 4 * size);
		idx = get_matrix_from_input(input_coeff, boundary_conditions, size);
		print_result(idx, size, permutations);
	}
	return (0);
}
