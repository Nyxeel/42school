/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/06/12 17:34:30 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>


void *addback(stack **tail, int num)
{
	stack *new_node = malloc(sizeof(stack));
	if (!new_node)
		return (NULL);
	new_node->value = num;
	new_node->prev = *tail;
	new_node->next = NULL;

	(*tail)->next = new_node;
	*tail = new_node;
	printf("Tail hinzugefügt\n"); /////////////////////////////////////////////////////////
}

stack	*create_head(stack *head, stack *tail, int num)
{
	head = malloc(sizeof(stack));
	if(!head)
		return (NULL);
	head->value = num;
	head->prev = NULL;
	head->next = NULL;
	*tail = *head;
	printf("Head erstellt\n"); /////////////////////////////////////////////////////////
	return (head);	
}

void	add_list(stack **a, int num)
{
	stack *head;
	stack *tail;

	head = NULL;
	tail = NULL;

	if (!a || !*a)
		a = create_head(&head, &tail, num);
	else if (addback(&tail, num) == NULL);
		free_list(&a);
	
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


void	free_list(stack **lst)
{
	stack	*tmp;

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

/* int	doubles(stack *a, int num)
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

void	create_stack(stack **a, char **av, int ac)
{
	int		i;
	long	num;

	i = 1;
	while (i < ac)
	{
		if (input_check(av[i]))
			free_list(&a);
		num = ft_atoi(av[i]);
		printf("NUM:%li\n", num);//////////////////////////////////////
		if (num < INT_MIN || num > INT_MAX)
			free_list(&a);
		/* if (doubles(*a, num))
			free_list(&a); */
		add_list(a, (int)num);
		i++;
	}
	printf("PASS\n");
	
}

int	main(int argc, char **argv)
{
	stack	*a;
	size_t	i;

	i = 0;
	a = NULL;
	if (argc < 2 || !argv[1][0])
		return (0);
	//stack_a = ft_split(argv[1][0], ' ');
	create_stack(&a, argv, argc);
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
