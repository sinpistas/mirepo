/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:21:54 by apestana          #+#    #+#             */
/*   Updated: 2023/08/27 22:25:29 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "checks.h"
#include "dictionary.h"
#include "translator.h"

int	main(int argc, char **argv)
{
	unsigned int	number;
	t_dictionary	*dic;
	int				res;
	int				keys;
	int				i;

	i = -1;
	if (number_check_atoi(argc, argv, &number) != 1)
		return (errors(-1));
	dic = NULL;
	res = mount_dictionary(&dic, &keys);
	if (res < 0)
		return (errors(res));
	if (argc == 2)
		if (translator(dic, keys, number) == -1)
			return (errors(-1));
	while (++i < keys)
	{
		free(dic[i].key);
		free(dic[i].word);
	}
	free(dic);
	return (0);
}
