/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:34:39 by apestana          #+#    #+#             */
/*   Updated: 2023/08/27 22:11:59 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSLATOR_H
# define TRANSLATOR_H
# define C 100
# include "dictionary.h"
# include <unistd.h>

void	finder(t_dictionary *dic, int keys, int num, int pos);

int		rosetta(t_dictionary *dic, int keys, char *num, int size);

int		translator(t_dictionary *dic, int keys, unsigned int number);

#endif