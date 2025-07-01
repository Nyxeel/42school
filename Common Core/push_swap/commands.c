/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:17:48 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/01 21:54:44 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(char id, t_stack **from, t_stack **to)
{
	t_node	*top;

	if (!from || !*from || !(*from)->head)
		return ;
	top = (*from)->head;
	(*from)->head = top->next;
	if ((*from)->head != NULL)
		(*from)->head->prev = NULL;
	else
		(*from)->tail = NULL;
	top->prev = NULL;
	top->next = (*to)->head;
	if ((*to)->head != NULL)
		(*to)->head->prev = top;
	else
		(*to)->tail = top;
	(*to)->head = top;
	(*from)->size -= 1;
	(*to)->size += 1;
	(*from)->operations += 1;
	if (id == 'a')
		write(1, "pa\n", 3);
	else if (id == 'b')
		write(1, "pb\n", 3);
}

void	swap(char id, t_stack **stack)
{
	t_node	*first;
	t_node	*second;

	if (!(*stack)->head || (*stack)->size < 2)
	{
		printf("FAIL"); //////////////////////////////////////////////////////////////
		return ;
	}
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
	(*stack)->operations += 1;
	if (id == 'a')
		write(1, "sa\n", 3);
	else if (id == 'b')
		write(1, "sb\n", 3);
}

void	rotate(char id, t_stack **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->head || (*stack)->size < 2)
		return ;
	first = (*stack)->head;
	last = (*stack)->tail;
	(*stack)->head = first->next;
	(*stack)->head->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	(*stack)->tail = first;
	(*stack)->operations += 1;
	if (id == 'a')
		write(1, "ra\n", 3);
	else if (id == 'b')
		write(1, "rb\n", 3);
	else if (id == 'r')
		write(1, "rr\n", 3);
}

void	r_rotate(char id, t_stack **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->head || (*stack)->size < 2)
		return ;
	first = (*stack)->head;
	last = (*stack)->tail;
	last->prev->next = NULL;
	(*stack)->tail = last->prev;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	(*stack)->head = last;
	(*stack)->operations += 1;
	if (id == 'a')
		write(1, "rra\n", 4);
	else if (id == 'b')
		write(1, "rrb\n", 4);
	else if (id == 't')
		write(1, "rrr\n", 4);

}
