/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/01 22:31:13 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_clear(t_stack **a)
{
	t_node	*curr;

	if (!(*a)->head)
		return ;
	curr = (*a)->head;
	while (curr->next != NULL)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);
}

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}


bool	add_node(t_stack **a, int value)
{
	t_node	*curr;

	curr = create_node(value);
	if (!curr)
		return (false);
	if (!(*a)->head)
	{

		(*a)->head = curr;
		(*a)->tail = curr;
	}
	else
	{
		(*a)->tail->next = curr;
		curr->prev = (*a)->tail;
		(*a)->tail = curr;
	}
	(*a)->size++;
	return (true);
}

bool	number_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+' )
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	doubles(t_stack **a, int num)
{
	t_node	*curr;

	curr = (*a)->head;
	while (curr != NULL)
	{
		if (curr->value == num)
			return (write(2, "DOUBLES\n", 8), false); /////////////////
		curr = curr->next;
	}
	return (true);
}

bool	input_check(t_stack **a, char **av)
{
	size_t	i;
	long	num;

	i = 1;
	while (av[i])
	{
		if (!number_check(av[i]))
			return (false);
		num = ft_atoi(av[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (false);
		if ((*a)->head && !doubles(a, num))
			return (printf("false\n"), false);
		if (!add_node(a, num))
			return (false);
		i++;
	}
	return (true);
}

void	print_stack_a(t_stack *a)
{
	size_t	i;
	t_node *curr;


	curr = a->head;
	

	i = 0;
	while (curr)
	{
		printf("Node[%zu]: %i\t\tTarget in B: %i \tCOSTS: %i\n", i, curr->value, curr->target->value, a->cheapest->cost + a->cheapest->target->cost);
		curr = curr->next;
		i++;
	}
}

void	print_stack_b(t_stack *b)
{
	size_t	i;
	t_node *curr;

	curr = b->head;
	i = 0;
	while (curr)
	{
		printf("Node[%zu]: %i\n", i, curr->value);
		curr = curr->next;
		i++;
	}
}


/* void	start_sorting(t_stack *a, t_stack *b)
{

} */



int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	//int i = 0;

	a = ft_calloc(1, sizeof(t_stack));
	if (!a)
		return (write(2, "ERROR\n", 7));
	b = ft_calloc(1, sizeof(t_stack));
	if (!b || argc < 2 || !argv[1])
		return (stack_clear(&a), free(a), write(2, "2ERROR\n", 7));
	/* if (argc == 2)
		argv = ft_split(argv[1][0], ' '); */
	if (!input_check(&a, argv))
		return (stack_clear(&a), stack_clear(&b), free(a), free(b), write(1, "3ERROR\n", 7));

	start_sorting(a, b);

	printf("\n_________A_________\n");
	print_stack_a(a);

	printf("--------------------\n");
	printf("\n_________B_________\n");
	print_stack_b(b);
	printf("\n");

	printf("CHEAPEST in A: %i - COSTS to TOP: %i\n",  a->cheapest->value, a->cheapest->cost);
	printf("TARGET in B: %i - COSTS to TOP: %i\n",  a->cheapest->target->value, a->cheapest->target->cost);
	printf("TOTAL COSTS: %i \n", a->cheapest->target->cost + a->cheapest->cost);

	stack_clear(&a);
	stack_clear(&b);
	free(a);
	free(b);
	return (0);
}
