/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionaryaux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:05:03 by apestana          #+#    #+#             */
/*   Updated: 2023/08/27 18:42:26 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionaryaux.h"

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

int	count_keys(void)
{
	int		characters_read;
	char	buffer;
	int		res;
	int		fd;

	res = 0;
	fd = open("numbers.dict", O_RDONLY);
	if (fd < 0)
		return (-2);
	characters_read = read(fd, &buffer, 1);
	while (characters_read > 0)
	{
		if (buffer == '\n')
			res++;
		characters_read = read(fd, &buffer, 1);
	}
	close(fd);
	return (res);
}

unsigned int	ft_dic_check(char c)
{
	int	state;

	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
	{
		state = 1;
	}
	else if (c >= '0' && c <= '9')
		state = 2;
	else if (c == ':')
		state = 3;
	else
		state = 4;
	return (state);
}
