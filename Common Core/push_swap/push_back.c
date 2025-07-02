/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/02 21:51:54 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
				rotate('a', &a);
			}
		}
		else
		{
			while (i ++ < a->size - target->index)
			{
				r_rotate('a', &a);
			}
		}
	push('a', &b, &a);
}
