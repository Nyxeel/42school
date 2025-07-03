/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/02 23:59:49 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			return (write(2, "Error\n", 6));
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
			return (write(2, "Error\n", 6));
		if (!add_node(a, num))
			return (false);
		i++;
	}
	return (true);
}