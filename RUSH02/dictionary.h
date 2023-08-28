/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:01:42 by apestana          #+#    #+#             */
/*   Updated: 2023/08/27 18:42:15 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H
# include "dictionaryaux.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_struct
{
	char	*key;
	char	*word;
}	t_dictionary;

char			*ft_read_key(int fd, int *res);

char			*ft_read_word(int fd, int *res);

t_dictionary	mount_structure(int fd, int *res);

int				mount_dictionary(t_dictionary **s_dictionary, int *keys);

#endif