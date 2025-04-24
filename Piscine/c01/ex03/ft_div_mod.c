/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:56:06 by pjelinek          #+#    #+#             */
/*   Updated: 2025/02/10 14:56:17 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int a;
    int b;
    int div;
    int mod;

    a = 64;
    b = 10;
    
    ft_div_mod(a, b, &div, &mod);
    printf("div (6): %d\nmod (4): %d", div, mod);
}
*/
