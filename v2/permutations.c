/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabderra <nabderra@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:19:14 by nabderra          #+#    #+#             */
/*   Updated: 2023/08/22 10:19:16 by nabderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

void	swap(u8 *a, u8 *b)
{
	u8	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	permutation(u8 *arr, struct s_pair pair, u8 *all_rows, int *rows_idx)
{
	u8				i;
	struct s_pair	new_pair;

	if (pair.beg == pair.end)
	{
		i = 0;
		while (i <= pair.end)
		{
			all_rows[*rows_idx] = arr[i];
			*rows_idx += 1;
			++i;
		}
	}
	else
	{
		i = pair.beg;
		while (i <= pair.end)
		{
			swap((arr + pair.beg), (arr + i));
			new_pair = (struct s_pair){.beg = pair.beg + 1, .end = pair.end};
			permutation(arr, new_pair, all_rows, rows_idx);
			swap((arr + pair.beg), (arr + i));
			++i;
		}
	}
}

u8	factorial(u8 size)
{
	u8	idx;
	u8	fact;

	idx = size;
	fact = 1;
	while (idx > 1)
	{
		fact *= idx;
		--idx;
	}
	return (fact);
}

static u8	*alloc_permutations_vector(u8 size)
{
	int	num_permutations;
	u8	*all_perms;

	num_permutations = factorial(size);
	all_perms = malloc(size * num_permutations);
	return (all_perms);
}

u8	*build_permutations_vector(u8 size)
{
	u8				*all_perms;
	u8				initial_perm[SIZE];
	u8				idx;
	int				all_perms_idx;
	struct s_pair	pair;

	all_perms = alloc_permutations_vector(size);
	idx = 0;
	while (idx < size)
	{
		initial_perm[idx] = idx + 1;
		++idx;
	}
	all_perms_idx = 0;
	pair.beg = 0;
	pair.end = size - 1;
	permutation(initial_perm, pair, all_perms, &all_perms_idx);
	return (all_perms);
}
