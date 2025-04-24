/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:22:46 by mchoma            #+#    #+#             */
/*   Updated: 2025/02/23 16:51:00 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "printing_3_numbers.h"
//#include "utils.h"

int	loop(char *dict, char *str, int counter, char **dest)
{
	int	print;
	int	error;
	int	len;

	len = lenght(str);
	error = 1;
	while (counter < len)
	{
		print = 0;
		print = print_3_digits(dict, &str[counter], dest);
		if (print == -1)
			return (-1);
		if (counter + 3 < len && print == 1)
		{
			if (!append(dest, " "))
				return (0);
			counter += 3;
			error = print_scale(dict, len - counter, dest);
			if (error == 0)
				return (-1);
		}
		else if (counter + 3 >= len)
		{
			counter += 3;
			return (1);
		}
		else
			counter += 3;
	}
	return (1);
}

int	mod0(char *dict, char *str, int counter, char **dest)
{
	int	error;
	int	len;

	len = lenght(str);
	error = 0;
	error = print_first_digits(dict, &str[counter], dest);
	if (error == -1)
		return (-1);
	counter += 3;
	if (counter < len)
	{
		if (!append(dest, " "))
			return (0);
		error = print_scale(dict, len - counter, dest);
		if (error == 0)
			return (-1);
	}
	else if (counter >= len)
		return (1);
	error = loop(dict, str, counter, dest);
	if (error == -1)
		return (-1);
	return (1);
}

int	mod1(char *dict, char *str, int counter, char **dest)
{
	int	error;
	int	len;

	len = lenght(str);
	error = 1;
	error = print_ones(dict, &str[0], dest);
	if (error == 0)
		return (-1);
	counter ++;
	if (counter == len)
		return (1);
	if (!append(dest, " "))
		return (0);
	error = print_scale(dict, len - counter, dest);
	if (error == 0)
		return (-1);
	error = loop(dict, str, counter, dest);
	if (error == -1)
		return (-1);
	return (1);
}

int	mod2(char *dict, char *str, int counter, char **dest)
{
	int	error;
	int	len;

	len = lenght(str);
	error = 1;
	if (str[0] == '1')
	{
		error = print_teen(dict, &str[0], dest);
		if (error == 0)
			return (-1);
	}
	else
	{
		error = print_tens(dict, &str[0], dest);
		if (error == 0)
			return (-1);
		if (str[1] != '0')
		{
			if (!append(dest, " "))
				return (0);
			error = print_ones(dict, &str[1], dest);
			if (error == 0)
				return (-1);
		}
	}
	counter = 2;
	if (counter == len)
		return (1);
	if (!append(dest, " "))
		return (0);
	error = print_scale(dict, len - counter, dest);
	if (error == 0)
		return (-1);
	error = loop(dict, str, counter, dest);
	if (error == -1)
		return (-1);
	return (1);
}

int	split_to_blocks(char *dict, char *str, char **dest)
{
	int	len;
	int	counter;
	int	error;

	len = lenght(str);
	error = 1;
	counter = 0;
	if (len % 3 == 0)
	{
		error = mod0(dict, str, counter, dest);
	}
	else if (len % 3 == 1)
	{
		error = mod1(dict, str, counter, dest);
	}
	else if (len % 3 == 2)
	{
		error = mod2(dict, str, counter, dest);
	}
	if (error == -1)
		return (-1);
	return (1);
}
