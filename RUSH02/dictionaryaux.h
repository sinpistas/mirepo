/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionaryaux.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:05:31 by apestana          #+#    #+#             */
/*   Updated: 2023/08/27 18:42:20 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARYAUX_H
# define DICTIONARYAUX_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char			*ft_strcpy(char *dest, char *src);

int				count_keys(void);

unsigned int	ft_dic_check(char c);

#endif