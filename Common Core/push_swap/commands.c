/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:17:48 by netrunner         #+#    #+#             */
/*   Updated: 2025/06/14 22:53:39 by pjelinek         ###   ########.fr       */
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
	else
		(*to)->tail = curr;
	(*to)->head = curr;
	(*from)->size -= 1;
	(*to)->size += 1;
}

void	swap(char id, t_stack **swap)
{
	t_node	*first;
	t_node	*second;

	if (!swap || !*swap || !(*swap)->head || (*swap)->size < 2)
		return ;
	first = (*swap)->head;
	second = (*swap)->head->next;
	(*swap)->head = curr->next;
	if ((*swap)->head != NULL)
		(*swap)->head->prev = NULL;
	else
		(*swap)->tail = NULL;
	(*swap)->head->next = curr;
	curr->prev = ((*swap)->head);
	if (curr->next != NULL)
		curr->next = curr->next->next;

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
