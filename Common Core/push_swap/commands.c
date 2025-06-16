/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:17:48 by netrunner         #+#    #+#             */
/*   Updated: 2025/06/16 13:06:58 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **from, t_stack **to)
{
	t_node	*curr;

	if (!from || !*from || !(*from)->head)
		return ;
	curr = (*from)->head;
	(*from)->head = curr->next;
	if ((*from)->head != NULL)
		(*from)->head->prev = NULL;
	else
		(*from)->tail = NULL;
	curr->next = (*to)->head;
	if ((*to)->head != NULL)
		(*to)->head->prev = curr;
	else(*from)->head
		(*to)->tail = curr;
	(*to)->head = curr;
	(*from)->size -= 1;
	(*to)->size += 1;
}

void	push(t_stack **from, t_stack **to)
{
	t_node	*curr;
	t_node	*to;

	if (!from || !*from || !(*from)->head)
		return ;
	curr = (*from)->head;

	to = (*to)->head;
	curr = curr->next;
	if ((*from)->head != NULL)
		(*from)->head->prev = NULL;
	else
		(*from)->tail = NULL;
	curr->next = (*to)->head;
	if ((*to)->head != NULL)
		(*to)->head->prev = curr;
	else
		(*to)->tail = curr;
	(*to)->head = curr;
	(*from)->size -= 1;
	(*to)->size += 1;
}

void	swap(char id, t_stack **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->head || (*stack)->size < 2)
		return ;
	first = (*stack)->head;
	second = (*stack)->head->next;

	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	else
		(*stack)->tail = first;
	
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	(*stack)->head = second;

	
	// AUSGABE
	if (id == 'a')
		write(1, "sa\n", 3);
	else if (id == 'b')
		write(1, "sb\n", 3);
}

int main()
{
	int *a;
	int	*b;

	a = malloc(10);

	b = a;
	free(b);
	return 0;
}
