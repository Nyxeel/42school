/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:38:33 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/02 15:38:35 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count]) 
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *join;
	size_t i;
	size_t j;

	i = 0;
	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	while(s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while(s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

int	main(void)
{
	char s1[] = "Hallo, ";
	char s2[] = "Welt!";
	char* join = ft_strjoin(s1, s2);
	printf("%s\n", join);
	free(join);
}