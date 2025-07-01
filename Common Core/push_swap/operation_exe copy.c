/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_exe copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/01 22:42:22 by pjelinek         ###   ########.fr       */
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
	t_node	*node;
	t_node	*target;
	int		i;

	i = 0;
	node = a->cheapest;
	target = a->cheapest->target;
	int total_costs = node->cost + target->cost;

	if (node->first_half == true && target->first_half == true)
	{
		while (i ++ <= find_min(node->cost, target->cost))
			rr(a, b);
		i = 0;
		while (i ++ <= total_costs - find_min(node->cost, target->cost))
		{
			if (node->cost > target->cost)
				rotate('a', &a);
			else
				rotate('b', &b);
		}

	}

	else if (node->first_half == false && target->first_half == false)
	{
		while (i ++ <= find_min(node->cost, target->cost))
			rrr(a, b);
		i = 0;
		while (i ++ <= total_costs - find_min(node->cost, target->cost))
		{
			if (node->cost > target->cost)
				r_rotate('a', &a);
			else
				r_rotate('b', &b);
		}
	}

	else
	{
		while (i ++ < node->cost)
			rotate('a', &a);
		i = 0;
		while (i ++ < target->cost)
			rotate('b', &b);
	}
}
