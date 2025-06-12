/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/06/12 20:09:58 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	free_list(list **lst)
{
	list	*tmp;

	printf("ERROR\n"); /////////////////////////////////////////////////////////
	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
	exit(1);
}

int	add_back(list **tail, int num)
{
	list	*curr;

	curr = malloc(sizeof(list));
	if (!curr)
		return (1);
	curr->value = num;
	curr->prev = *tail;
	curr->next = NULL;

	if (*tail != NULL)
		(*tail)->next = curr;
	*tail = curr;
	printf("Tail hinzugefügt\n"); //////////////////////////////////////////
	return (0);
}

list	*create_head(list **head, list **tail, int num)
{
	list	*new;

	new = malloc(sizeof(list));
	if (!head)
		return (NULL);
	new->value = num;
	new->prev = NULL;
	new->next = NULL;
	*tail = new;
	*head = new;
	printf("Head erstellt\n"); ////////////////////////////////////////////////
	return (*head);
}

void	add_list(list **a, int num)
{
	list	*head;
	list	*tail;

	head = NULL;
	tail = NULL;

	if (!a || !*a)
		*a = create_head(&head, &tail, num);
	else if (add_back(&tail, num))
		free_list(a);

}

long	ft_atoi(const char *str)
{
	int		minus;
	long	num;
	size_t	i;

	i = 0;
	minus = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = minus * (-1);
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10;
		num = num + str[i] - '0';
		i++;
	}
	return (minus * num);
}




/* int	doubles(list *a, int num)
{
	while (a != NULL)
	{
		if (a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
} */

int	input_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+' )
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	create_list(list **a, char **av, int ac)
{
	int		i;
	long	num;

	i = 1;
	while (i < ac)
	{
		if (input_check(av[i]))
			free_list(a);
		num = ft_atoi(av[i]);
		printf("NUM:%li\n", num);//////////////////////////////////////
		if (num < INT_MIN || num > INT_MAX)
			free_list(a);
		/* if (doubles(*a, num))
			free_list(&a); */
		add_list(a, (int)num);
		i++;
	}
	printf("PASS\n");

}

int	main(int argc, char **argv)
{
	list	*a;

	a = NULL;
	if (argc < 2 || !argv[1][0])
		return (0);
	//list_a = ft_split(argv[1][0], ' ');
	create_list(&a, argv, argc);
	/* if (!sorted(a))
	{
		if (size(a) == 2)
			sort_two(a);
		else if (size(a) == 3)
			sort_three(a);
		else
			start_algorithm(a);
	}
	free(a); */
	return (0);
}
