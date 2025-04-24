/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_3_numbers.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:13:17 by mchoma            #+#    #+#             */
/*   Updated: 2025/02/23 23:24:27 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "utils.h"
#include "call_dict.h"
#include "print_1.h"

int	dummy(char *dict, char *str, char **dest)
{
	int	error;

	error = 1;
	if (str[1] != '0')
	{
		if (!append(dest, " "))
			return (0);
		if (print_tens(dict, &str[1], dest) == 0)
			return (-1);
	}
	return (1);
}

//this funcion prints 3 digits the pointer need to be moved outside
int	print_3_digits(char *dict, char *str, char **dest)
{
	int	error;

	error = 1;
	if (str[0] != '0')
	{
		error = print_100(dict, str, dest);
		if (error == 0 || error == -1)
			return (error);
	}
	if (str[1] == '1')
	{
		error = print_11(dict, str, dest);
		if (error == 0 || error == -1)
			return (error);
		return (1);
	}
	else
		dummy(dict, str, dest);
	if (str[2] != '0')
	{
		error = print_1(dict, str, dest);
		if (error == 0 || error == -1)
			return (error);
	}
	return (1);
}

int	print_first_digits(char *dict, char *str, char **dest)
{
	int	error;

	error = 1;
	if (str[0] != '0')
	{
		if (print_hundreds (dict, &str[0], dest) == 0)
			return (-1);
	}
	error = print_first_10(dict, str, dest);
	if (error == 0 || error == -1)
		return (error);
	if (str[2] != '0')
	{
		if (!append(dest, " "))
			return (0);
		if (print_ones(dict, &str[2], dest) == 0)
			return (-1);
	}
	return (1);
}
