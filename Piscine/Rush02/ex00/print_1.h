/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:26:01 by mchoma            #+#    #+#             */
/*   Updated: 2025/02/23 23:28:08 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	dummy(char *dict, char *str, char **dest);

int	print_100(char *dict, char *str, char **dest)
{
	if (!append(dest, " "))
		return (0);
	if (print_hundreds(dict, &str[0], dest) == 0)
		return (-1);
	return (1);
}

int	print_11(char *dict, char *str, char **dest)
{
	if (!append(dest, " "))
		return (0);
	if (print_teen(dict, &str[1], dest) == 0)
		return (-1);
	return (1);
}

int	print_1(char *dict, char *str, char **dest)
{
	if (!append(dest, " "))
		return (0);
	if (print_ones(dict, &str[2], dest) == 0)
		return (-1);
	return (1);
}

int	print_first_10(char *dict, char *str, char **dest)
{
	if (str[1] == '1')
	{
		if (!append(dest, " "))
			return (0);
		if (print_teen(dict, &str[1], dest) == 0)
			return (-1);
		return (1);
	}
	else
	{
		if (dummy(dict, str, dest) == -1)
			return (-1);
	}
	return (1);
}
