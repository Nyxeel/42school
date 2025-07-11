/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strncmp_real_launcher.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 02:08:15 by netrunner         #+#    #+#             */
/*   Updated: 2025/07/06 14:40:53 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libunit.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && str1[i] && str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}

void	stack_clear(t_stack **a)
{
	t_node	*curr;
	t_node	*tmp;

	if (!a || !*a || !(*a)->head)
		return ;
	curr = (*a)->head;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	(*a)->head = NULL;
	(*a)->tail = NULL;
}


void free_all(t_stack **list)
{
	if (list && *list)
	{
		stack_clear(list);
		free(*list);
		*list = NULL;
	}
}


void	load_test(t_stack *list, char *name, int (*test_func) (void), bool demo)
{
	t_node *node;

	node = calloc(1, sizeof(t_node));
	if (!node)
		return ;
	node->test_name = name;
	node->func = test_func;
	node->demo = demo;
	node->next = NULL;
	if(!list->head)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}
	list->size += 1;
}

int launch_tests(t_stack *list)
{
	t_node *curr;
	int	result;
	int success = 0;
	int status;
	bool demo;
	
	curr = list->head;
	if (curr->demo)
	{
		printf("\n\t**** DEMO TESTS RUNNING ****\n\n");
		demo = true;
	}
	else
		printf("\n\t**** REAL TESTS RUNNING****\n\n");
	while (curr)
	{
		int id = fork();
		if (id == -1)
			return (free_all(&list), -1);
		if (id == 0)
		{
			result = curr->func();
			free_all(&list);
			exit(result);
		}
		else
		{
			id = wait(&status);
			if (id == -1)
				return (free_all(&list), -1);
			printf("%s : %s : ", list->routine, curr->test_name);
			sleep(1);
			if (WIFEXITED(status))
			{
				if (WEXITSTATUS(status) == 0)
				{
					printf("\033[32m[OK]\033[0m\n");
					success++;
				}
				else
					printf("\033[31m[KO]\033[0m\n");
			}	
			if (WIFSIGNALED(status))
			{
				if (WTERMSIG(status) == SIGSEGV)
					printf("\033[31m[SIGSEGV]\033[0m\n");
				else if (WTERMSIG(status) == SIGBUS)
					printf("\033[31m[SIGBUS]\033[0m\n");
			}
		}
		sleep(1);
		curr = curr->next;
	}
	if (demo)
		printf("\nDemo Tests OK\n");
	else
		printf("\n%i/%i Tests OK\n", success, list->size);
	if (success == list->size)
		return (free_all(&list), 0);
	return (free_all(&list), -1);
}

int strncmp_real_launcher(void)
{
	t_stack	*list;
	int		result;

	list = calloc(1, sizeof(t_stack));
	if (!list)
		return (-1);
	list->size = 0;
	list->routine = "STRNCMP";
	load_test(list, "salut vs. salut", &salut_test, false);
	load_test(list, "test vs. testss", &test_testss, false);
	load_test(list, "test vs. tEsts", &test_tEst, false);
	load_test(list, "empty vs. test", &empty_test, false);
	load_test(list, "test vs. empty", &test_empty, false);
	load_test(list, "abc vs. abcde", &abc_xyz, false);
	load_test(list, "test\\200 vs test\\0", &unsigned_test, false);
	result = launch_tests(list);
	return(result);
}

int	main(void)
{
	int counter;
	counter = strncmp_real_launcher();
	if (counter == 0)
		//run_real_tests();
	

	return (0);
	/*isalnum_launcher();
	....

	....*/
}