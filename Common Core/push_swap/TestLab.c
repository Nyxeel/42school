/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestLab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/02 12:28:35 by netrunner        ###   ########.fr       */
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
	push('b', &a, &b);
	push('b', &a, &b);
	

	//int i = 0;
	
	while (a->size > 3)
	{
		////////////////////////////////////////////
		printf("\nListsize: %i\n", a->size);
		set_max(b);
		set_min(b);

		// SET TARGET NODE IN B
		set_targets(a, b);

		set_index(a);
		set_index(b);
		// FIND CHEAPEST NODE
		find_cheapest(a, b);
		
		printf("\n_________A_________\n");
		print_stack_a(a);

		printf("--------------------\n");
		printf("\n_________B_________\n");
		print_stack_b(b);
		printf("\n");

		printf("CHEAPEST in A: %i - COSTS to TOP: %i\n",  a->head->cheapest->value, a->head->cheapest->cost);
		printf("TARGET in B: %i - COSTS to TOP: %i\n",  a->head->target->value, a->head->target->cost);
		printf("TOTAL COSTS: %i \n", a->head->target->cost + a->head->cheapest->cost);
 
		// EXECUTE OPERATIONS
		operation_exec(a, b);
	
	/* 	a->head->cheapest = NULL;
		a->head->target = NULL; */
		//i++;
	}
	sort_three(a);
	
	printf("\nListsize: %i\n", a->size);
	printf("\n_________A_________\n");
	print_stack_a(a);

	printf("--------------------\n");
	printf("\n_________B_________\n");
	print_stack_b(b);
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
		exit(1);

	// PUSH BACK FROM B TO A

		// SET TARGET NODE IN A
		//set_targets(&a, &b);


	// PRINT OPERATIONS

	printf("Operations: %i\n", a->operations + b->operations);

}

