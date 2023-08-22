/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visible_boxes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabderra <nabderra@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:32:20 by nabderra          #+#    #+#             */
/*   Updated: 2023/08/22 10:33:23 by nabderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

u8	visible_boxes_ltr(u8 row[], u8 len)
{
	u8	idx;
	u8	count;
	u8	current_max;

	idx = 0;
	count = 0;
	current_max = 0;
	while (current_max < len)
	{
		if (row[idx] > current_max)
		{
			current_max = row[idx];
			++count;
		}
		++idx;
	}
	return (count);
}

u8	visible_boxes_rtl(u8 row[], u8 len)
{
	u8	idx;
	u8	count;
	u8	current_max;

	idx = 0;
	count = 0;
	current_max = 0;
	while (current_max < len)
	{
		if (row[len - 1 - idx] > current_max)
		{
			current_max = row[len - 1 - idx];
			++count;
		}
		++idx;
	}
	return (count);
}
