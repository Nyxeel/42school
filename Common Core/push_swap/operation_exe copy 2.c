/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_exe copy 2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/02 17:59:31 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *a, t_stack *b)
{
	r_rotate('f', &a);
	r_rotate('t', &b);
	a->operations -= 1;
}

void	rr(t_stack *a, t_stack *b)
{
	rotate('f', &a);
	rotate('r', &b);
	a->operations -= 1;
}

int	find_min(int node_cost, int target_cost)
{
	if (node_cost < target_cost)
		return (node_cost);
	else
		return (target_cost);
}

void	operation_exec(t_stack *a, t_stack *b)
{
	t_node	*cheapest;
	t_node	*target;
	int		i;

	i = 0;
	cheapest = find_cheapest(a);
	target = cheapest->target;

	// Immer zuerst beide korrekt an den Anfang holen
	if (cheapest->first_half && target->first_half)
	{
		while (i < find_min(cheapest->cost, target->cost))
		{
			rr(a, b);
			i++;
		}
		i = 0;
		while (i < find_max(cheapest->cost, target->cost) - find_min(cheapest->cost, target->cost))
		{
			if (cheapest->cost > target->cost)
				rotate('a', &a);
			else
				rotate('b', &b);
			i++;
		}
	}
	else if (!cheapest->first_half && !target->first_half)
	{
		while (i < find_min(cheapest->cost, target->cost))
		{
			rrr(a, b);
			i++;
		}
		i = 0;
		while (i < find_max(cheapest->cost, target->cost) - find_min(cheapest->cost, target->cost))
		{
			if (cheapest->cost > target->cost)
				r_rotate('a', &a);
			else
				r_rotate('b', &b);
			i++;
		}
	}
	else
	{
		while (a->head != cheapest)
		{
			if (cheapest->index <= a->size / 2)
				rotate('a', &a);
			else
				r_rotate('a', &a);
		}
		while (b->head != target)
		{
			if (target->index <= b->size / 2)
				rotate('b', &b);
			else
				r_rotate('b', &b);
		}
	}

	// FINAL: sicherstellen, dass cheapest wirklich oben ist
	while (a->head != cheapest)
	{
		if (cheapest->index <= a->size / 2)
			rotate('a', &a);
		else
			r_rotate('a', &a);
	}

	push('b', &a, &b);
}
