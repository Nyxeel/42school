/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestLab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/06/10 21:11:04 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	ft_error(t_stack **lst)
{
	t_stack	*tmp;
	printf("ERROR\n");
	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

int	input_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	create_stack(t_stack **a, char **av, int ac)
{
	int	i;
	//size_t	num;

	i = 1;
	printf("1. INPUT OK\n");
	while (i < ac)
	{
		if (input_check(av[i]))
			ft_error(a);
		i++;
	}
	printf("INPUT OK\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	size_t	i;

	i = 0;
	a = NULL;
	if (argc < 2 || !argv[1])
		return (write(1, "FAIL\n", 5));
	//stack_a = ft_split(argv[1][0], ' ');
	create_stack(&a, argv, argc);
	return (0);
}

