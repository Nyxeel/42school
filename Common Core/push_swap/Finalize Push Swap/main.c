/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:51:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/03 18:17:08 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = ft_calloc(1, sizeof(t_stack));
	if (!a)
		return (write(2, "Error\n", 6));
	b = ft_calloc(1, sizeof(t_stack));
	if (!b || argc < 2 || !argv[1])
		return (free_all(a, b), write(2, "Error\n", 6));
	/* if (argc == 2)
		argv = ft_split(argv[1][0], ' '); */
	if (!input_check(a, argv))
		return (free_all(a, b), write(2, "Error\n", 6));
	start_sorting(a, b);
	free_all(a, b);
	return (0);
}
