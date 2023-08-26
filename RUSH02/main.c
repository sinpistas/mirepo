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

#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "checks.h"
#include "dicctionary.h"

int	main(int argc, char **argv)
{
	unsigned int	number;
	char			b;
	int				fd;
	int				leidos;

	if (number_check_atoi(argc, argv, &number) != 1)
		write (1, "Error\n", 6);
	fd = open("numbers.dict", O_RDONLY);
	if(fd < 0)
		return(-1);
	leidos = read(fd, &b, 1);
	while (leidos != 0)
	{
		write(1, &b, 1);
		leidos =read(fd, &b, 1);
	}
	close(fd);
}
