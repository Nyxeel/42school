/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/03 17:44:05 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	costs(t_node *node, t_stack *stack)
{
	int			cost;

	if (node->index <= stack->size / 2)
		cost = node->index;
	else
		cost = stack->size - node->index;
	return (cost);
}

void	set_index(t_stack *stack)
{
	t_node	*node;
	int		idx;

	if (!stack || !stack->head)
		return ;
	idx = 0;
	node = stack->head;
	while (node)
	{
		node->index = idx;
		if (node->index <= stack->size / 2)
			node->first_half = true;
		else
			node->first_half = false;
		idx++;
		node = node->next;
	}
}

void	find_cheapest(t_stack *from, t_stack *to)
{
	t_node	*node;
	long	min_cost;
	int		total_cost;

	if (!from || !from->head || !to || !to->head)
		return ;
	node = from->head;
	min_cost = INT_MAX;
	while (node)
	{
		node->cost = costs(node, from);
		node->target->cost = costs(node->target, to);
		if (node->first_half == node->target->first_half)
			total_cost = find_max(node->cost, node->target->cost);
		else
			total_cost = node->cost + node->target->cost;
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			from->cheapest = node;
		}
		node = node->next;
	}
}
