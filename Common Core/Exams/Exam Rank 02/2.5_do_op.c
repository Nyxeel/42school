/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.5_do_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:12:49 by netrunner         #+#    #+#             */
/*   Updated: 2025/08/04 14:12:24 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* 
Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$ */



#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void putnbr(int num)
{
	long int nb;
	nb = num;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
	if (nb >= 0 && nb <= 9)
	{
		nb += '0';
		write(1, &nb, 1);
	}
}

int	ft_do_op(char *nb, char op, char *nb2)
{
	int result;
	int num;
	int num2;
	
	num = atoi(nb);
	num2 = atoi(nb2);
	if (op == '*')
		result = num * num2;
	else if (op == '/')
		result = num / num2;
	else if (op == '%')
		result = num % num2;
	else if (op == '+')
		result = num + num2;
	else if (op == '-')
		result = num - num2;
	return (result);	
}

int	main(int ac, char **av)
{
	if (ac == 4)
		putnbr(ft_do_op(av[1], av[2][0], av[3]));
	write(1, "\n", 1);
	return (0);
}