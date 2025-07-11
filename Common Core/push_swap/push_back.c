/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/03 16:42:18 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_min_to_top(t_stack *a)
{
	t_node *top;

	set_minmax(a);
	set_index(a);
	top = a->min;
	while (a->head != top)
	{
		if (top->first_half)
			rotate('a', a);
		else
			r_rotate('a', a);
	}
}

void	push_back(t_stack *a, t_stack *b)
{
	t_node *target;
	int i;

	i = 0;
	target = b->head->target;
		if (target->first_half == true)
		{
			while (i ++ < target->index)
			{
				rotate('a', a);
			}
		}
		else
		{
			while (i ++ < a->size - target->index)
			{
				r_rotate('a', a);
			}
		}
	push('a', b, a);
}
