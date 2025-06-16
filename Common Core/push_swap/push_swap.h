/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:18:57 by netrunner         #+#    #+#             */
/*   Updated: 2025/06/16 18:21:49 by pjelinek         ###   ########.fr       */
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
	int				cheapest;
	int				operations;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
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

#endif
