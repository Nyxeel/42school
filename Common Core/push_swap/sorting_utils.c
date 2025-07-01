/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/01 11:07:21 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//////				CALC CHEAPEST NODE



int	calc(t_node *node, t_stack *stack)
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

	idx = 0;
	node = stack->head;
	while (node)
	{
		node->index = idx;
		idx++;
		node = node->next;
	}
}

void	find_cheapest(t_stack *a, t_stack *b)
{
	t_node	*node;
	long	min_cost;
	int		cost;

	set_index(a);
	set_index(b);
	cost = 0;
	node = a->head;
	min_cost = INT_MAX;
	while (node)
	{
		cost = calc(node, a) + calc(node->target, b);
		node->cost = cost;	
		if (node->next && node->cost < min_cost)
		{
			min_cost = node->cost;
			a->cheapest = node;
			a->cheapest->cost = node->cost;
		}
		node = node->next;
	}
}



/////////		SORTING UTILS



void	set_targets(t_stack *a, t_stack *b)
{
	t_node	*node_a;
	t_node	*node_b;
	long	max_value;

	node_a = a->head;
	while (node_a)
	{
		node_a->target = NULL;
		max_value = INT_MIN;
		node_b = b->head;
		while (node_b)
		{
			if (node_b->value < node_a->value && node_b->value > max_value)
			{
				max_value = node_b->value;
				node_a->target = node_b;
			}
			node_b = node_b->next;
		}
	if (!node_a->target)
		node_a->target = b->max;		
	node_a = node_a->next;
	}
}

void	set_max(t_stack *stack)
{
	t_node	*curr;

	stack->max = stack->head;
	curr = stack->head;
	while (curr)
	{
		if (curr->value > stack->max->value)
			stack->max = curr;
		curr = curr->next;
	}
}

void	set_min(t_stack *stack)
{
	t_node	*curr;

	stack->min = stack->head;
	curr = stack->head;
	while (curr)
	{
		if (curr->value < stack->min->value)
			stack->min = curr;
		curr = curr->next;
	}
}

bool	sorted(t_stack *a)
{
	t_node	*curr;

	curr = a->head;
	while (curr != NULL)
	{
		if (curr->next && curr->value > curr->next->value)
			return (false);
		curr = curr->next;
	}
	return (true);
}
