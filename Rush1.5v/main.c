/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:21:54 by apestana          #+#    #+#             */
/*   Updated: 2023/08/26 22:03:45 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "checks.h"
#include "dictionary.h"

int	main(int argc, char **argv)
{
	unsigned int	number;
	t_dictionary	*dic;
	int				res;
	int				keys;

	if (number_check_atoi(argc, argv, &number) != 1)
		return (errors(-1));
	dic = NULL;
	res = mount_dictionary(&dic, &keys);
	if (res < 0)
		return (errors(res));
	for(int i = 0; i < keys; i++)
	{
		printf("%s - %s\n",dic[i].key,dic[i].word);
	}
}
