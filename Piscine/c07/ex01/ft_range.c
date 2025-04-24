/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:05:54 by pjelinek          #+#    #+#             */
/*   Updated: 2025/02/27 18:07:52 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*str;
	int	i;

	if (min >= max)
		return (NULL);
	str = (int *)malloc((max - min) * sizeof(int));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < max - min)
	{
		str[i] = min + i;
		i++;
	}
	return (str);
}
/*
int main(void)
{
    int min;
    int max;
    int i;
    int *range;

    min = 16;
    max = 28;
    range = ft_range(min, max);
    i = 0;
    while(i < max - min)
    {
        printf("%d\n", range[i]);
        i++;
    }
    free(range);
    return (0);

}*/
