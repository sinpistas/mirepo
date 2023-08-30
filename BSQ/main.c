/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:03:24 by apestana          #+#    #+#             */
/*   Updated: 2023/08/29 21:12:59 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "auxiliar.h"
#include "init_matrix.h"
#include "draw_matrix.h"
#include "memory.h"
#include <unistd.h>
#define N 1000000

int	loop(int argc, char **argv, t_map s_map, char *str)
{
	int	i;
	int	res;

	i = 0;
	while (++i < argc)
	{
		if (read_file(str, argv[i]) == -2)
			if (error(-3, i, argc))
				continue;
		res = firstline_check(str);
		if (res == -1)
			if (error(-3, i, argc))
				continue;
		if (mount_matrix(&s_map, str, res) == -1)
			if (error(-3, i, argc))
				continue;
		init_matrix(&s_map);
		draw_matrix(&s_map);
		if (i < argc - 1)
			write(1,"\n",1);
		destroy(&s_map, 0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	s_map;
	char	str[N];
	int		res;
	
	if (argc < 1)
		return (0);
	if (argc == 1)
		if (read_keyboard(str) == -2)
			return (error(-3,0,0));
	if (argc == 2)
		if (read_file(str, argv[1]) == -2)
			return (error(-3,0,0));
	if (argc > 2)
		return (loop(argc,argv,s_map,str)); 
	res = firstline_check(str);
	if (res == -1)
		return (error(-1,0,0));
	if (mount_matrix(&s_map, str, res) == -1)
		return (error(-1,0,0));
	init_matrix(&s_map);
	draw_matrix(&s_map);
	destroy(&s_map, 0);
	return (0);
}
