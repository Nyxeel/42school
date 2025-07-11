/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:15:32 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/06 17:17:54 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

#include "libft/libft.h"
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

typedef struct s_node
{
	bool			demo;
	char			*test_name;
	int				(* func)(void); 
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;      
	int		size;
	char	*routine;
} t_stack;


/* int strlen_launcher(void);
int ok_test_strlen(void);
int ko_test_strlen(void);
int segfault_test_strlen(void);
int	sigbus_test_strlen(void); */

//int basic_test(void);

// ************ REAL TESTS ***************

int strlen_real_launcher(void);
int hallo_test(void);
int number_test(void);
int lorem_ipsum_test(void);
int empty_string_test(void);
int white_spaces_test(void);
int many_spaces_test(void);


//real strncmp
int salut_test(void);
int test_testss(void);
int test_tEst(void);
int empty_test(void);
int test_empty(void);
int abc_xyz(void);
int unsigned_test(void);

//real strchr
int	b_test(void);
int	o_test(void);
int	j_test(void);
int	s_test(void);
int empty_test_strchr(void);




/* ======= FRAMEWORK ======= */
/* cmp_nums.c */




#endif