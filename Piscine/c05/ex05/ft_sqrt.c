/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:31:26 by pjelinek          #+#    #+#             */
/*   Updated: 2025/02/24 16:34:54 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	n;

	n = 1;
	if (nb < 0)
		return (0);
	while (n < nb)
	{
		if (n * n == nb)
			return (n);
		n++;
	}
	return (0);
}
/*
int main()
{
    int nb = 400;
    
    printf("Ergebnis: %d\n", ft_sqrt(nb));
}*/
