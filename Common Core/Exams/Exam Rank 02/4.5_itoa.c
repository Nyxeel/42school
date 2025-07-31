/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.5_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:09:16 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/31 11:29:58 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	wordcount(int num)
{
	int i;

	i = 0;
	if (num <= 0)
		i++;
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	long int 	nb;
	int			wordlen;
	char		*num;
	int			index;

	nb = nbr;
	wordlen = wordcount(nb);
	num = malloc(wordlen + 1);
	if (!num)
		return (NULL);
	num[wordlen] = '\0';
	if (nb < 0)
	{
		num[0] = '-';
		nb = -nb;
	}
	index = wordlen - 1;
	while (nb > 9)
	{
		num[index] = nb % 10 + '0';
		nb /= 10;
		index--;
	}
	num[index] = nb + '0';
	return (num);
}


int	main(int ac, char** av)
{
	char * arr =  ft_itoa(455);
	printf("%s", arr);
	free(arr);
}


