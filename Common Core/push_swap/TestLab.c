/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestLab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/06/28 00:20:47 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	turk_sort(a, b);
{
	// FIND TARGET

	// FIND CHEAPEST

	// EXECUTE OPERATIONS

	// SET MAX & SET MIN
}
 */


void	start_algorithm(t_stack *a, t_stack *b)
{
	push('b', &a, &b);
	push('b', &a, &b);
	push('b', &a, &b);
	push('b', &a, &b);
	push('b', &a, &b);
	set_max(b);
	set_min(b);

	printf("MAX VALUE: %i\n", b->max->value);///////////////////////////////////
	printf("MIN VALUE: %i\n", b->min->value);///////////////////////////////////

	while(a->size != 3)
	{
		set_targets(a, b);

		// FIND CHEAPEST NODE
		// find_cheapest(a, b);

		// EXECUTE OPERATIONS

		a->size -= 1;

	}

}


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
	else
		printf("SORTED!!!\n");

	// PUSH BACK FROM B TO A



	// PRINT OPERATIONS

	printf("Operations: %i\n", a->operations + b->operations);

}

