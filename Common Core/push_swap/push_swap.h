/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:18:57 by netrunner         #+#    #+#             */
/*   Updated: 2025/06/12 21:14:55 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				cheapest;
	int				operations;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
	bool			first_half;
}	t_node;

typedef struct s_stack
{
	node	*head;
	node	*tail;
	node	*min; 		///kleinster Wert im Stack
	node	*max;		///größter Wert im Stack
	int		size;		/// Listengröße
	bool	sorted;		///Sortiert ? Yes : No
	char	id;
}	t_stack


#endif
