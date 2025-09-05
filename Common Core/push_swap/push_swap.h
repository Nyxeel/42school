/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:18:57 by netrunner         #+#    #+#             */
/*   Updated: 2025/09/05 13:52:45 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
//# include <stdio.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
	bool			first_half;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	t_node	*min;
	t_node	*max;
	t_node	*cheapest;
	int		size;
}	t_stack;

// -------------------- INPUT & ERROR HANDLING --------------------
bool		input_check(t_stack *a, char **av);

// -------------------- MEMORY & UTILS --------------------
void		ft_bzero(void *s, size_t n);
long long	ft_atoi(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
void		free_all(t_stack *a, t_stack *b);

// -------------------- STACK COMMANDS --------------------
void		swap(char id, t_stack *stack);
void		push(char id, t_stack *from, t_stack *to);
void		rotate(char id, t_stack *stack);
void		r_rotate(char id, t_stack *stack);

// -------------------- SORTING ALGORITHM CORE --------------------
void		start_sorting(t_stack *a, t_stack *b);
void		sort_min_to_top(t_stack *a);
bool		sorted(t_stack *a);

// -------------------- COST & INDEX MANAGEMENT --------------------
void		set_index(t_stack *stack);
void		set_minmax(t_stack *stack);
int			find_max(int costA, int costB);
int			find_min(int node_cost, int target_cost);

// -------------------- TARGETS & CHEAPEST CALC --------------------
void		set_targets_in_a(t_stack *a, t_stack *b);// Zielzuweisung für B->A
void		set_targets_in_b(t_stack *a, t_stack *b);// Zielzuweisung für A->B
void		find_cheapest(t_stack *from, t_stack *to);

// -------------------- PUSH UTILS --------------------
void		push_to_b(t_stack *a, t_stack *b);// Schiebe von A nach B
void		push_back(t_stack *a, t_stack *b);// Schiebe von B zurück nach A

#endif
