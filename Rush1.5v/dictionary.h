/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dicctionary.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:01:42 by apestana          #+#    #+#             */
/*   Updated: 2023/08/26 22:07:07 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H

typedef struct s_struct
{
	char	*key;
	char	*word;
} t_dictionary;

int	count_keys(void);

int	mount_dictionary(t_dictionary **s_dictionary);

#endif
