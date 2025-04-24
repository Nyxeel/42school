/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:57:30 by pjelinek          #+#    #+#             */
/*   Updated: 2025/02/10 14:57:32 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}
/*
int	main(void)
{
    char* text;

    text = "This is a string of 56 characters which should output 58";
    
    printf("It should be: 56 Chars\n");
    int count = ft_strlen(text);
    
    printf("\nOutput: %d chars", count); 
}
*/
