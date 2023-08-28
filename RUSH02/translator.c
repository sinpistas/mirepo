/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:34:59 by apestana          #+#    #+#             */
/*   Updated: 2023/08/27 22:18:23 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"
#include "rosettatools.h"

int	rosetta(t_dictionary *dic, int keys, char *num, int size)
{
	int		i;
	int		index;

	i = 0;
	(void) keys;
	while (i < size)
	{
		index = num[i] - '0';
		ft_putstr(dic[index].word);
		ft_putstr(" ");
		i++;
	}
	return (0);
}

int	translator(t_dictionary *dic, int keys, unsigned int number)
{
	int		size;
	char	num[C];

	size = ft_itost(number, num);
	if (rosetta(dic, keys, num, size) == -1)
		return (-1);
	return (1);
}
