/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:31:21 by apestana          #+#    #+#             */
/*   Updated: 2023/08/27 18:43:10 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_H
# define CHECKS_H
# include <unistd.h>

unsigned int	ft_check(char c, int **sign);

int				ft_atoi(char *str, unsigned long long int *res, int *sig);

int				number_check_atoi(int argc, char **argv, unsigned int *number);

int				errors(int number);

#endif