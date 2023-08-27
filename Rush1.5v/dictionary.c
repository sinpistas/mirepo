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
#include "dictionaryaux.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

char *ft_read_key(int fd, int *res)
{
	char	aux[512];
	int 	characters_read;
	char	buffer;
	int		len;
	char	*p;
	len = 0;
	characters_read = read(fd, &buffer, 1);
	while (characters_read != 0 && buffer != ':')
	{

		if(ft_dic_check(buffer) != 1)
		{
			aux[len] = buffer;
			len++;
		}
		characters_read = read(fd, &buffer, 1);
	}
	aux[len] = '\0';
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		*res = -3;
	else
		strcpy(p,aux);
	return (p);
}

char	*ft_read_word(int fd, int *res)
{
	char	aux[512];
	int 	characters_read;
	char	buffer;
	int		len;
	char	*p;

	len = 0;
	characters_read = read(fd, &buffer, 1);
	while (characters_read != 0 && buffer != '\n')
	{
		if(ft_dic_check(buffer) != 1)
		{
			aux[len] = buffer;
			len++;
		}
		characters_read = read(fd, &buffer, 1);
	}
	aux[len] = '\0';
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		*res = -3;
	else
		strcpy(p,aux);
	return (p);
}

t_dictionary	mount_structure(int fd, int *res)
{
	t_dictionary	s_p;
	int				copy;

	s_p.key = ft_read_key(fd, &copy);
	if(copy == -1)
		*res = copy;
	else
	{
		s_p.word = ft_read_word(fd, &copy);
		if(copy == -1)
			*res = copy;
	}
	return(s_p);
}

int	mount_dictionary(t_dictionary **s_dictionary, int *keys)
{
	int	fd;
	int	i;
	int	res;
	t_dictionary *p;
	*keys = count_keys();
	if(*keys == -2)
		return (-2);
	p = (t_dictionary *)malloc((*keys ) * sizeof(t_dictionary));
	if (p == NULL)
		return (-3);
	fd = open("numbers.dict", O_RDONLY);
	if(fd < 0)
		return (-2);
	i = 0;
	while(i < *keys)
	{
		p[i] = mount_structure(fd,&res);
		if (res == -3)
			return (res);
		i++;
	}
	*s_dictionary = p;
	close(fd);
	return (1);
}


