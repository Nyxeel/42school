/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:18:57 by netrunner         #+#    #+#             */
/*   Updated: 2025/06/12 20:09:47 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				cheapest;
	int				operations;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
	bool			first_half;
}	list

typedef struct s_stackmeta
{
	stack	*head;
	stack	*tail;
	stack	*min; 		///kleinster Wert im Stack
	stack	*max;		///größter Wert im Stack
	int		size;		/// Listengröße
	bool	sorted;		///Sortiert ? Yes : No
	char	id;
}	stack


#endif
