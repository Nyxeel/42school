/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_dict.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:12:44 by mchoma            #+#    #+#             */
/*   Updated: 2025/02/23 22:32:55 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

void	ft_error(int c);

char	*ft_get_num(char *dict, char *num);

int	print_ones(char *dict, char *str, char **dest)
{
	char	*ter;
	char	*tmp;

	ter = malloc(sizeof(char) * 2);
	if (ter == 0)
	{
		ft_error(1);
		return (0);
	}
	ter [0] = str [0];
	ter [1] = 0;
	tmp = ft_get_num(dict, ter);
	if (*tmp == 0 || !append(dest, tmp))
	{
		free(tmp);
		free(ter);
		return (0);
	}
	free(tmp);
	free(ter);
	return (1);
}

int	print_tens(char *dict, char *str, char **dest)
{
	char	*ter;
	char	*tmp;	

	ter = malloc(sizeof(char) * 3);
	if (ter == 0)
	{
		ft_error(1);
		return (0);
	}
	ter [0] = str [0];
	ter [1] = '0';
	ter [2] = 0;
	tmp = ft_get_num(dict, ter);
	if (*tmp == 0 || !append(dest, tmp))
	{
		free(tmp);
		free(ter);
		return (0);
	}
	free(tmp);
	free(ter);
	return (1);
}

int	print_teen(char *dict, char *str, char **dest)
{
	char	*ter;
	char	*tmp;	

	ter = malloc(sizeof(char) * 3);
	if (ter == 0)
	{
		ft_error(1);
		return (0);
	}
	ter [0] = str [0];
	ter [1] = str [1];
	ter [2] = 0;
	tmp = ft_get_num(dict, ter);
	if (*tmp == 0)
	{
		free(tmp);
		free(ter);
		return (0);
	}
	if (!append(dest, tmp))
	{
		free(tmp);
		free(ter);
		return (0);
	}
	free(ter);
	free(tmp);
	return (1);
}

int	print_hundreds(char *dict, char *str, char **dest)
{
	char	*ter;
	char	*tmp;

	ter = malloc(sizeof(char) * 2);
	if (ter == 0)
	{
		ft_error(1);
		return (0);
	}
	ter [0] = str [0];
	ter [1] = 0;
	tmp = ft_get_num(dict, ter);
	if (*tmp == 0)
	{
		free(tmp);
		free(ter);
		return (0);
	}
	if (!append(dest, tmp))
	{
		free(tmp);
		free(ter);
		return (0);
	}
	free(ter);
	free(tmp);
	if (!append(dest, " "))
		return (0);
	tmp = ft_get_num(dict, "100");
	if (*tmp == '0')
	{
		return (0);
	}
	if (!append(dest, tmp))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

int	print_scale(char *dict, int scale, char **dest)
{
	char	*str;
	char	*tmp;	
	int		counter;

	if (scale < 2)
		return (1);
	str = malloc(sizeof(char) * (scale + 3));
	if (str == 0)
	{
		ft_error(1);
		return (0);
	}
	counter = 1;
	str [0] = '1';
	while (counter <= scale)
	{
		str[counter] = '0';
		counter ++;
	}
	str[counter] = 0;
	tmp = ft_get_num(dict, str);
	if (*tmp == 0)
	{
		free(tmp);
		free(str);
		return (0);
	}
	if (!append(dest, tmp))
	{
		free(str);
		free(tmp);
		return (0);
	}
	free(str);
	free(tmp);
	return (1);
}
