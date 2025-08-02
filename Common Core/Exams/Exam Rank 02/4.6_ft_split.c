/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.6_ft_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:09:16 by pjelinek          #+#    #+#             */
/*   Updated: 2025/08/01 09:53:21 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>



/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
 */

int ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}


size_t	ft_wordcount(char *str)
 {
	int i = 0;
	bool inword;
	size_t count = 0;

	while (str[i])
	{
		if (ft_isspace(str[i]))
			inword = false;
		else if(!inword)
		{
			inword = true;
			count++;
		}
		i++;
	}
	return (count);
 }



char *split_copy(char *str)
{
	int i = 0;
	int count = 0;
	while (!ft_isspace(str[count]) && str[count])
		count++;
	char *split = malloc(count + 1);
	if (!split)
		return (NULL);
	while (i < count && str[i])
	{
		split[i] = str[i];
		i++;
	}
	split[i] = '\0';
	return (split);
}

char    **ft_split(char *str)
{
	if (!str)
	return (NULL);
	int words = ft_wordcount(str);
	char **split = (char **)malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	int i = 0;
	int j = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
		{
			split[j] = split_copy(&str[i]);
			if (!split)
				return (NULL);
			j++;
			while (!ft_isspace(str[i]) && str[i])
				i++;
			if (str[i] == 0)
			{
				split[j] = NULL;
				return (split);
			}
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}


int	main(int ac, char** av)
{
	char *arr = "Hallo liebe Welt! Es ist schön hier!";
	char **split = ft_split(arr);
	int i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}


