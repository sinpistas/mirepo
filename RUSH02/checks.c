/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:31:23 by apestana          #+#    #+#             */
/*   Updated: 2023/08/26 22:03:48 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checks.h"

unsigned int	ft_check(char c)
{
	int	state;

	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
	{
		state = 1;
	}
	else if (c == '+' )
	{
		state = 2;
	}
	else if (c >= '0' && c <= '9')
		state = 3;
	else
		state = 4;
	return (state);
}

unsigned int	ft_atoi(char *str, unsigned int *res)
{
	unsigned int			i;
	unsigned int			state;
	unsigned int			start;
	unsigned long long int	add;

	i = 0;
	add = 0;
	start = 0;
	while (str[i] != '\0')
	{
		state = ft_check(str[i]);
		if (start <= state && state != 4)
			start = state;
		else
			break ;
		if (start == 3)
		{
			add = add * 10 + str[i] - '0';
			if (add > 4294967295)
				return (4);
		}
		i++;
	}
	*res = add;
	return (state);
}

int	number_check_atoi(int argc, char **argv, unsigned int *number)
{
	int				ok;
	unsigned int	copy;

	if (argc == 1)
		return (-1);
	else if (argc == 2 || argc == 3)
	{
		if (argv[argc - 1][0] == '\0')
			return (-1);
		ok = ft_atoi(argv[argc - 1], &copy);
		*number = copy;
		if (ok == 4)
			return (-1);
	}
	return (1);
}
