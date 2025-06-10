/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/06/10 11:35:07 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	input_check(char **av, int ac)
{
	int	i;
	size_t	j;

	/* if (*arguments == NULL)
		return (0); */
	i = 1;
	while (i < ac)
	{
		if 
	}
	return (1);
}

void *create(stack)
{
	size_t i = 0;
	while(stack[i])
	{
		if (wrong_sytnax[stack[i]])
			return (NULL);
		num = ft_atoi(stack[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (NULL);
		add_node(num);

	}
}

int	main(int argc, char **argv)
{
	stack	a;
	char 	**stack_a;
	size_t 	i = 0;

	if (argc < 2 || !argv)
		return 0;
	stack_a = ft_split(argv[1][0], ' ');
	a = create(stack_a);
	if(wrong_order(a))
	{
		if (size(a) == 2)
			sort_two(a);
		else if (size(a) == 3)
			sort_three(a);
		else
			start_algorithm(a);
	}
	free(a);
	return 0;
}
	
	if (input_check(argv, argc) == 1)
		printf("SUCCESS");
	else
		printf("ERROR");


/* 		
	typedef	struct	stack
	{
		int		number;
		struct	stack *next;
	}			stack_list;

 */
	return (0);
}