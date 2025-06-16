/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestLab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/06/14 12:42:21 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	stack_clear(t_stack **a)
{
	if (!a || !*a)
		return ;
	t_node *curr;

	curr = (*a)->head;
	while (curr->next != NULL)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);
	(*a)->head = NULL;
	(*a)->tail = NULL;
	exit(1);
}

t_node	*create_node(int value)
{
	t_node *new_node;

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
	t_node *curr;
	
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
		printf("NUM:%li\n", num);//////////////////////////////////////
		if (num < INT_MIN || num > INT_MAX)
			return (false);
		if (!add_node(a, (int)num))
			return (false);
		//if (sorted)
		
		//if (doubles)

		i++;
	}
	printf("INPUT CHECK PASS\n");
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;

	a = NULL;
	b = a;
	a->id = 'a';
	b->id = 'b';
	a->size = 0;
	b->size = 0;
	a->sorted = true;
	b->sorted = true;

	if (argc < 2 || !argv[1])
		return (write(1, "ERROR\n", 6));
	//a = ft_split(argv[1][0], ' ');

	if (!input_check(&a, argv))
		stack_clear(&a);

	return (0);
}