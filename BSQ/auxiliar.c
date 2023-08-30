/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:44:46 by apestana          #+#    #+#             */
/*   Updated: 2023/08/29 16:23:57 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "auxiliar.h"
#include <unistd.h>

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

int	error(int number, int row, int max)
{
	if (number == -3)
		write(1, "map error", sizeof("map error"));
	if (number == -3 && row < max - 1)
		write(1, "\n", 1);
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	if (dest != NULL && src != NULL)
	{
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}