/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:49:06 by apestana          #+#    #+#             */
/*   Updated: 2023/08/22 09:44:30 by nabderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_string(char str[])
{
	int	i;
	int	alternate;

	i = 0;
	alternate = 0;
	while (str[i] != '\0')
	{
		if (alternate == 0 && str[i] >= '1' && str[i] <= '4')
			alternate = 1;
		else if (alternate == 1 && str[i] == ' ')
			alternate = 0;
		else
			return (-1);
		i++;
	}
	if (i != 31)
		return (-1);
	return (1);
}

void	input_initializer(u8 *input, char *str, u8 len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		input[i] = str[i * 2] - '0';
		i++;
	}
}
