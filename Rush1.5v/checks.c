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
#include <unistd.h>

unsigned int	ft_check(char c, int **sign)
{
	int	state;

	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
	{
		state = 1;
	}
	else if (c == '+' || c == '-')
	{
		state = 2;
		if (c == '-')
			**sign = (**sign) * (-1);
	}
	else if (c >= '0' && c <= '9')
		state = 3;
	else if (c == '.')
		state = 5;
	else
		state = 4;
	return (state);
}

int	ft_atoi(char *str, unsigned long long int *res, int *sig)
{
	unsigned int			i;
	int						state;
	int						start;
	int						valid;

	i = -1;
	start = 0;
	valid = -1;
	while (str[++i] != '\0')
	{
		state = ft_check(str[i], &sig);
		if (start <= state && state != 4)
			start = state;
		else
			break ;
		if (start == 3)
		{
			valid = 1;
			*res = (*res) * 10 + str[i] - '0';
		}
		if (*res > 4294967295 || start == 5)
				return (-1);
	}
	return (valid);
}

int	number_check_atoi(int argc, char **argv, unsigned int *number)
{
	int						ok;
	unsigned long long int	copy;
	int 					sig;

	if (argc == 1)
		return (-1);
	else if (argc == 2 || argc == 3)
	{
		if (argv[argc - 1][0] == '\0')
			return (-1);
		copy = 0;
		sig = 1;
		ok = ft_atoi(argv[argc - 1], &copy, &sig);
		if (ok == -1 || copy < 0 || sig == -1)
			return (-1);
		*number = copy;
	}
	return (1);
}

int	errors(int	number)
{
	if (number == -1)
		write (1, "Error\n", 6);
	if (number == -2)
		write(1, "Dict Error\n", 11);
	if (number == -3)
		write(1, "Malloc Error\n", 13);

	return (-1);
}
