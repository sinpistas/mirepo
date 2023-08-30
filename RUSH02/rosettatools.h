/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rosettatools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:54:42 by apestana          #+#    #+#             */
/*   Updated: 2023/08/27 21:56:43 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROSETTATOOLS_H
# define ROSETTATOOLS_H
# include <unistd.h>

void	ft_rev_int_tab(char *tab, int size);

int		ft_itost(unsigned int number, char *str_number);

void	ft_putstr(char *str);

#endif