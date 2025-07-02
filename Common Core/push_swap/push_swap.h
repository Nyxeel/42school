/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:18:57 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/02 14:30:20 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>



typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
	struct s_node	*cheapest;
	bool			first_half;
}	t_node;



typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	t_node	*min;		///kleinster Wert im Stack
	t_node	*max;		///größter Wert im Stack
	int		size;		/// Listengröße
	bool	sorted;		///Sortiert ? Yes : No
	char	id;
	int		operations;
}	t_stack;




/// UTILS
void	ft_bzero(void *s, size_t n);
long	ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);



///	COMANDS
void	swap(char id, t_stack **stack);
void	push(char id, t_stack **from, t_stack **to);
void	rotate(char id, t_stack **stack);
void	r_rotate(char id, t_stack **stack);



// SORTING

void	start_sorting(t_stack *a, t_stack *b);
void	set_max(t_stack *stack);
void	set_min(t_stack *stack);
int		find_max(int costA, int costB);
bool	sorted(t_stack *a);
void	set_targets(t_stack *a, t_stack *b);


void	set_new_targets(t_stack *a, t_stack *b);
void	find_cheapest(t_stack *a, t_stack *b);
void	set_index(t_stack *stack);
void	operation_exec(t_stack *a, t_stack *b);
void	push_back(t_stack *a, t_stack *b);


void	print_stack_a(t_stack *a);
void	print_stack_b(t_stack *a);

#endif