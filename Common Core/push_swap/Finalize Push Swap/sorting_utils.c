/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/08/14 14:23:10 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(int costA, int costB)
{
	if (costA < costB)
		return (costB);
	else
		return (costA);
}

void	set_targets_in_a(t_stack *a, t_stack *b)
{
	t_node	*node_a;
	t_node	*node_b;
	long	min_value;

	if (!a || !a->head || !b || !b->head)
		return ;
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

void	set_targets_in_b(t_stack *a, t_stack *b)
{
	t_node	*node_a;
	t_node	*node_b;
	long	max_value;

	if (!a || !a->head || !b || !b->head)
		return ;
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

void	set_minmax(t_stack *stack)
{
	t_node	*curr;

	if (!stack || !stack->head)
		return ;
	stack->max = stack->head;
	stack->min = stack->head;
	curr = stack->head;
	while (curr)
	{
		if (curr->value > stack->max->value)
			stack->max = curr;
		if (curr->value < stack->min->value)
			stack->min = curr;
		curr = curr->next;
	}
}

bool	sorted(t_stack *a)
{
	t_node	*curr;

	if (!a || !a->head)
		return (1);
	curr = a->head;
	while (curr != NULL)
	{
		if (curr->next && curr->value > curr->next->value)
			return (false);
		curr = curr->next;
	}
	return (true);
}
