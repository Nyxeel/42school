/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:39:53 by pjelinek          #+#    #+#             */
/*   Updated: 2025/02/27 17:55:27 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strcpy(char *dest, char *src, int pos)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[pos + i] = src[i];
		i++;
	}
	return (dest);
}

int	ft_lens(char **strarr, int size, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		count += ft_strlen(strarr[i]);
		if (i < size - 1)
			count += ft_strlen(sep);
		i++;
	}
	return (count);
}

char	*ft_finalize(int size, char *dest, char *sep, char **strs)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	dest[0] = '\0';
	while (i < size)
	{
		ft_strcpy(dest, strs[i], pos);
		pos += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(dest, sep, pos);
			pos += ft_strlen(sep);
		}
		i++;
	}
	dest[pos] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;

	if (size == 0)
	{
		dest = malloc(sizeof(char));
		*dest = 0;
		return (dest);
	}
	dest = malloc((ft_lens(strs, size, sep) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest = ft_finalize(size, dest, sep, strs);
	return (dest);
}
/*
int main(void)
{
    int size = 3;
    char *strs[] = {"Hallo", "liebe", "Welt"};
    char *sep = "-+-+-";
	
    printf("%s\n", ft_strjoin(size, strs, sep));
	return (0);
}*/
