/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabderra <nabderra@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:27:45 by nabderra          #+#    #+#             */
/*   Updated: 2023/08/22 10:27:48 by nabderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
#define RUSH_H

#define u8 unsigned char
#define SIZE 4

struct	s_pair {
	u8	beg;
	u8	end;
};

void	compute_bc_for_matrix(u8 *boundary_condition, u8 *perm_matrix, u8 size);

u8		*compute_boundary_conditions(u8 *permutation_matrix, u8 size);

int		compare_coeff(u8 *input_coeff, u8 *boundary_condition, u8 size);

int		get_matrix_from_input(u8 *input_coeff, u8 *boundary_condition, u8 size);
#endif
