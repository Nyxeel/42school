/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/03 03:22:50 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_three(t_stack *a)
{
	set_max(a);
	if (a->max == a->head)
		rotate('a', &a);
	else if (a->max == a->head->next)
		r_rotate('a', &a);
	if (!sorted(a))
		swap('a', &a);
}

void	start_algorithm(t_stack *a, t_stack *b)
{
	if (a->size > 3)
		push('b', &a, &b);
	if (a->size > 3)
		push('b', &a, &b);
	while (a->size > 3)
	{
		set_minmax(b);
		set_targets_in_b(a, b);
		set_index(a);
		set_index(b);
		find_cheapest(a, b);
		exec_operations(a, b);
	}
	sort_three(a);
	while (b->head)
	{
		set_minmax(a);
		set_targets_in_a(a, b);
		set_index(a);
		push_back(a, b);
	}
	sort_min_to_top(a);
}

void	start_sorting(t_stack *a, t_stack *b)
{
	if (!sorted(a))
	{
		if (a->size == 2)
			swap('a', &a);
		else if (a->size == 3)
			sort_three(a);
		else
			start_algorithm(a, b);
	}
	printf("Operations: %i\n", a->operations + b->operations);
}

