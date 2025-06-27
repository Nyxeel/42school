/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/06/27 21:29:21 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_targets(t_stack *a, t_stack *b)
{
	t_node	*aa;
	t_node	*bb;

	aa = a->head;
	while (aa)
	{
		bb = b->head;
		while (bb)
		{
			if (aa->value < b->min->value)
				aa->target = b->max;
			if (a)
			bb = bb->next;
		}
	aa = aa->next;
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

	curr = stack->head;
	stack->min = stack->head;
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
