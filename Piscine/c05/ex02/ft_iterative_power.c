/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:47:28 by pjelinek          #+#    #+#             */
/*   Updated: 2025/02/24 16:48:18 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power != 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}
/*
int main()
{
    int nb;
    int power;

    nb = 1;
    power = 0;
    
    printf("Ergebnis: %d\n", ft_iterative_power(nb, power));
}*/
