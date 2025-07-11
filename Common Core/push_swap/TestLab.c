/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestLab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/03 16:43:35 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a)
{
	size_t	i;
	t_node *curr;

	curr = a->head;
	i = 0;
	while (curr)
	{
		printf("Node[%zu]: %i\n", i, curr->value);
		curr = curr->next;
		i++;
	}
}



void	sort_three(t_stack *a)
{
	set_minmax(a);
	if (a->max == a->head)
		rotate('a', a);
	else if (a->max == a->head->next)
		r_rotate('a', a);
	if (!sorted(a))
		swap('a', a);
}


void	start_algorithm(t_stack *a, t_stack *b)
{
	push('b', a, b);
	push('b', a, b);


	//int i = 0;

	while (a->size > 3)
	{
		////////////////////////////////////////////
		printf("\nListsize: %i\n", a->size);
		set_minmax(b);
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

		printf("CHEAPEST in A: %i - COSTS to TOP: %i\n",  a->cheapest->value, a->cheapest->cost);
		printf("TARGET in B: %i - COSTS to TOP: %i\n",  a->cheapest->target->value, a->cheapest->target->cost);
		printf("TOTAL COSTS: %i \n", a->cheapest->target->cost + a->cheapest->cost);

		// EXECUTE OPERATIONS
		operation_exe(a, b);

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


	//////// PUSH BACK FROM B TO A

	printf("\n\nPUSHBACK\n\n");

	while (b->head)
	{
		set_minmax(a);

		// SET TARGET NODE IN A
		set_new_targets(a, b);

		set_index(a);


		//find_cheapest(a, b);

		push_back(a, b);
	}
	if (!sorted(a))
		sort_min_to_top(a);

	printf("\n_________A_________\n");
	print_stack(a);

	printf("--------------------\n");

}

void	start_sorting(t_stack *a, t_stack *b)
{
	if (!sorted(a))
	{
		if (a->size == 2)
			swap('a', a);
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

