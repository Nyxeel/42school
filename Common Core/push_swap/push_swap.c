/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/06/14 19:06:31 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	stack_clear(t_stack **a)
{
	t_node	*curr;

	if (!(*a)->head)
		exit(1);
	curr = (*a)->head;
	while (curr->next != NULL)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);
	free (*a);
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
			return (false);
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
			return (false);
		if (!add_node(a, num))
			return (false);
		//while ((*a)->head->value < (*a)->head->next->value)
		// IMPLEMENT SORTED CHECK !!!///////////////////////////////////////////

		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	//int i = 0;

	a = ft_calloc(1, sizeof(t_stack));
	if (!a)
		return (write(2, "ERROR\n", 6));
	b = a;

	if (argc < 2 || !argv[1])
		return (write(2, "ERROR\n", 6));
	//stack_a = ft_split(argv[1][0], ' ');
	if (!input_check(&a, argv))
		return (stack_clear(&a), write(1, "ERROR\n", 6));

	start_sorting(&a, &b);
/* 	while (a->head)
	{
		printf("Liste[%i]: %i\n", i, a->head->value);
		a->head = a->head->next;
		i++;
	} */
	stack_clear(&a);
	return (0);
}
