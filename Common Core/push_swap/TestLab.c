/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestLab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/02 02:57:18 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	sort_three(t_stack **a)
{
	set_max(a);
	if ((*a)->max == (*a)->head)
		rotate('a', a);
	else if ((*a)->max == (*a)->head->next)
		r_rotate('a', a);
	if (!sorted(a))
		swap('a', a);
}


void	start_algorithm(t_stack *a, t_stack *b)
{
	push('b', &a, &b);
	push('b', &a, &b);
	

	int i = 0;


	t_node *curr;
	curr = a->head;


	while (i < 10)
	{
	////////////////////////////////////////////
		set_max(&b);
		set_min(&b);

		// SET TARGET NODE IN B
		set_targets(&a, &b);

		set_index(&a);
		set_index(&b);
		// FIND CHEAPEST NODE
		find_cheapest(&a, &b);
		
	printf("\n_________A_________\n");
	print_stack_a(a);

	printf("--------------------\n");
	printf("\n_________B_________\n");
	print_stack_b(b);
	printf("\n");

	printf("CHEAPEST in A: %i - COSTS to TOP: %i\n",  curr->cheapest->value, curr->cheapest->cost);
	printf("TARGET in B: %i - COSTS to TOP: %i\n",  curr->target->value, curr->target->cost);
	printf("TOTAL COSTS: %i \n", curr->target->cost + curr->cheapest->cost);
 
		

		
	sort_three(&a);
	printf("\n_________A SORTED_________\n");
	print_stack_a(a); 

		// EXECUTE OPERATIONS
		operation_exec(&a, &b);

		i++;
	}
}

void	start_sorting(t_stack *a, t_stack *b)
{
	if (!sorted(&a))
	{
		if (a->size == 2)
			swap('a', &a);
		else if (a->size == 3)
			sort_three(&a);
		else
			start_algorithm(a, b);
	}
	else
		exit(1);

	// PUSH BACK FROM B TO A



	// PRINT OPERATIONS

	printf("Operations: %i\n", a->operations + b->operations);

}

