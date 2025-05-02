/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:36:15 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/02 15:18:40 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	minus;
	int	num;
	int	i;

	i = 0;
	minus = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = minus * (-1);
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10;						// 						1 = 1 * 10 = 10
		num = num + str[i] - '0';			// 0 + 49 - 48 = 1		10 + 52 - 48 = 14
		i++;
	}
	return (minus * num);
}

int main(void)
{
    char *c = NULL;
    int num;

    num = ft_atoi(c);
    printf("Nummer: %d\n", num);

}
