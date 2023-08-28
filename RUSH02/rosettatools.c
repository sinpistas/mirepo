/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rosettatools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:55:27 by apestana          #+#    #+#             */
/*   Updated: 2023/08/27 21:56:50 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

void	ft_rev_int_tab(char *tab, int size)
{
	int		i;
	char	aux;

	i = 0;
	while (i < size / 2)
	{
		aux = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = aux;
		i++;
	}
}

int	ft_itost(unsigned int number, char *str_number)
{
	int		i;

	i = 0;
	if (number == 0)
	{
		str_number[i++] = '0';
	}
	while (number != 0)
	{
		str_number[i] = (char)(number % 10) + '0';
		number = number / 10;
		i++;
	}
	str_number[i] = '\0';
	ft_rev_int_tab(str_number, i);
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
