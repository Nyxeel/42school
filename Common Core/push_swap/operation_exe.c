/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_exe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/02 17:13:20 by pjelinek         ###   ########.fr       */
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
	cheapest = a->cheapest;
	target = a->cheapest->target;
	int total_costs = cheapest->cost + target->cost;

	if (cheapest->first_half == true && target->first_half == true)
	{
		while (i < find_min(cheapest->cost, target->cost))
		{
			rr(a, b);
			i++;
		}
		i = 0;
		while (i < total_costs - find_min(cheapest->cost, target->cost))
		{
			if (cheapest->cost == target->cost)
				break;
			if (cheapest->cost > target->cost)
				rotate('a', &a);
			else
				rotate('b', &b);
			i++;
		}

	}

	else if (cheapest->first_half == false && target->first_half == false)
	{
		while (i < find_min(cheapest->cost, target->cost))
		{
			rrr(a, b);
			i++;
		}
		i = 0;
		while (i < total_costs - find_min(cheapest->cost, target->cost))
		{
			if (cheapest->cost == target->cost)
				break ;
			else if (cheapest->cost > target->cost)
				r_rotate('a', &a);
			else
				r_rotate('b', &b);
			i++;
		}
	}

	else
	{
		while (i < cheapest->cost)
		{
			if (cheapest->first_half == true)
				rotate('a', &a);
			else
				r_rotate('a', &a);
			i++;
		}
		i = 0;
		while (i < target->cost)
		{
			if (cheapest->target->first_half == true)
				rotate('b', &b);
			else
				r_rotate('b', &b);
			i++;
		}
	}

	push('b', &a, &b);


}
