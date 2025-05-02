/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:34:41 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/02 15:36:31 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static void f(unsigned int index, char *str)
{
	printf("index:%d\n", index);
	if(index < 5)
		*str = '*';
}


void	ft_striteri(char *s, void (*f)(unsigned int,char*))
{
	unsigned int i;

	i = 0;
	while(s[i])
	{
		printf("s[%d]: \n", i);
		f(i, &s[i]);
		i++;
	}

}

int	main(void)
{
	char src[] = "Der manipulierende Text"; 	// "*****anipulierende Text";
	
	ft_striteri(src, f);
	printf("%s", src);
}