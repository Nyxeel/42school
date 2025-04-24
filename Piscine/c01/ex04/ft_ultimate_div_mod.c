/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulimate_div_mod.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:56:49 by pjelinek          #+#    #+#             */
/*   Updated: 2025/02/10 14:56:52 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	zahl;

	zahl = *a;
	*a = *a / *b;
	*b = zahl % *b;
}
/*
int	main(void)
{
    int a;
    int b;

    a = 64;
    b = 10;

    ft_ultimate_div_mod(&a, &b);    
}
*/
