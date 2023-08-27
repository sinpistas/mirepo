/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dicctionary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:03:02 by apestana          #+#    #+#             */
/*   Updated: 2023/08/26 22:03:58 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	count_keys(void)
{
	int		characters_read;
	char	buffer;
	int		res;
	int		fd;

	fd = open("numbers.dict", O_RDONLY);
	if(fd < 0)
		return (-2);
	characters_read = read(fd, &buffer, 1);
	while (characters_read != 0)
	{
		if (buffer == '\n')
			res++;
		characters_read = read(fd, &buffer, 1);
	}
	close(fd);
	return (res);
}

#include <stdio.h>

int	mount_dictionary(t_dictionary **s_dictionary)
{
	int	keys;
	keys = count_keys();
	if(keys == -2)
		return (-2);
	s_dictionary = (t_dictionary **)malloc((keys + 1) * sizeof(t_dictionary*));
	if (s_dictionary == NULL)
		return (-3);
	s_dictionary[keys] = NULL;

	//A partir de aqui solo son pruebas
	s_dictionary[0] = (t_dictionary *)malloc(2* sizeof(t_dictionary));
	s_dictionary[0]->key = "s";
	printf("%s", s_dictionary[0]->key);
	return (1);
}


