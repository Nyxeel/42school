/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_exe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/03 16:42:08 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int node_cost, int target_cost)
{
	if (node_cost < target_cost)
		return (node_cost);
	else
		return (target_cost);
}

void	double_rotate(t_stack *a, t_stack *b)
{
	t_node	*cheapest;
	t_node	*target;
	int		i;

	i = 0;
	cheapest = a->cheapest;
	target = a->cheapest->target;
	while (i < find_min(cheapest->cost, target->cost))
	{
		rotate('f', a);
		rotate('r', b);
		a->operations -= 1;
		i++;
	}
	i = 0;
	while (i < find_max(cheapest->cost, target->cost) - find_min(cheapest->cost, target->cost))
	{
		if (cheapest->cost == target->cost)
			break;
		if (cheapest->cost > target->cost)
			rotate('a', a);
		else
			rotate('b', b);
		i++;
	}
}

void	double_rev_rotate(t_stack *a, t_stack *b)
{
	t_node	*cheapest;
	t_node	*target;
	int		i;

	i = 0;
	cheapest = a->cheapest;
	target = a->cheapest->target;
	while (i < find_min(cheapest->cost, target->cost))
	{
		r_rotate('f', a);
		r_rotate('t', b);
		a->operations -= 1;
		i++;
	}
	i = 0;
	while (i < find_max(cheapest->cost, target->cost) - find_min(cheapest->cost, target->cost))
	{
		if (cheapest->cost == target->cost)
			break ;
		else if (cheapest->cost > target->cost)
			r_rotate('a', a);
		else
			r_rotate('b', b);
		i++;
	}
}

void	move_to_top(t_stack *a, t_stack *b)
{
	t_node	*cheapest;
	t_node	*target;
	int		i;

	i = 0;
	cheapest = a->cheapest;
	target = a->cheapest->target;
	while (i < cheapest->cost)
	{
		if (cheapest->first_half == true)
			rotate('a', a);
		else
			r_rotate('a', a);
		i++;
	}
	i = 0;
	while (i < target->cost)
	{
		if (cheapest->target->first_half == true)
			rotate('b', b);
		else
			r_rotate('b', b);
		i++;
	}
}

void	operation_exe(t_stack *a, t_stack *b)
{
	t_node	*cheapest;
	t_node	*target;

	if (!a || !b || !a->cheapest)
		return ;
	cheapest = a->cheapest;
	target = a->cheapest->target;
	if (cheapest->first_half == true && target->first_half == true)
		double_rotate(a, b);
	else if (cheapest->first_half == false && target->first_half == false)
		double_rev_rotate(a, b);
	else
		move_to_top(a, b);
	push('b', a, b);
}
