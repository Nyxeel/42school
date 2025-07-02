/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/02 14:27:14 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//////				CALC CHEAPEST NODE

int	find_max(int costA, int costB)
{
	if (costA < costB)
		return (costB);
	else
		return (costA);
}

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
		if (node->index <= stack->size / 2)
			node->first_half = true;
		else
			node->first_half = false;
		idx++;
		node = node->next;
	}
}

void	find_cheapest(t_stack *a, t_stack *b)
{
	t_node	*node;
	long	min_cost;
	int cost = 0;


	node = a->head;
	min_cost = INT_MAX;
	while (node)
	{
		node->cost = calc(node, a);
		node->target->cost = calc(node->target, b);
		if ((node->first_half == true && node->target->first_half == true)
			|| (node->first_half == false && node->target->first_half == false))
			cost = find_max(node->cost, node->target->cost);
		else
			cost = node->cost + node->target->cost;
		if (node->next && cost < min_cost)
		{
			min_cost = cost;
			node->cheapest = node;
			/* (*a)->head->cost = node->cost;
			(*a)->head->target->cost = node->target->cost; */
		}
		node = node->next;
	}
}



/////////		SORTING UTILS



void	set_new_targets(t_stack *a, t_stack *b)
{
	t_node	*node_a;
	t_node	*node_b;
	long	min_value;

	node_b = b->head;
	while (node_b)
	{
		node_b->target = NULL;
		min_value = INT_MAX;
		node_a = a->head;
		while (node_a)
		{
			if (node_b->value < node_a->value && node_a->value < min_value)
			{
				min_value = node_a->value;
				node_b->target = node_a;
			}
			node_a = node_a->next;
		}
		if (!node_b->target)
			node_b->target = a->min;
		node_b = node_b->next;
	}
}



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
