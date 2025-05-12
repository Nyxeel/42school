/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1ft_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:05:14 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/12 18:00:42 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		result;

	if (!str)
		return (0);
	va_start(ap, str);
	result = ft_va_start(str, ap);
	va_end(ap);
	return (result);
}


int	main(void)
{
	//char c = 'a';
	//char *str2 = "Stream";

	//char *str = "Mein c % startet um f:d Uhr! e";
	//printf("ORIGINAL:Mein %c %% startet um %c:%c Uhr! %c\n", 'c', 'f', 'd', 'e');
	//printf("\nInput Strinlaenge: %zu\n", ft_strlen(str));
	//printf("%d Hexa: %p\n", 42, NULL);

	int i;
	//char p[10];


/*
	i = ft_printf("%s\n", "STREAM");	 	// String Return 	WORKING
	printf("String Laenge: %zu\nString Output: %d\n\n", ft_strlen("STREAM\n"), i);

	i = ft_printf("%c\n", 'c'); 				// Char Return  WORKING
	printf("Char Laenge: %zu\nChar Output: %d\n\n", ft_strlen("c\n"), i);


	i = ft_printf("%u", -42);	 		// Unsigned Return			WORKING
	printf("Unsigned Laenge: %zu\nUnsigned Output:%d\n", ft_strlen("4294967254"), i);

	int i = ft_printf("%i\n", -42);	 		// Int Return 	WORKING
	printf("Int Laenge: %zu\nInt Output: %d\n\n", ft_strlen("-42\n"), i); */

	i = ft_printf("%s\n%i\n%d\n%x\n%u\n", "TEST", 125, 765443, 45899, -1); 			// Hexa Return
	printf("\n\nPrintf Return: %d\n\n", i);
	printf("ORIGINAL:%x", -21);


/* 	i = ft_printf("Pointer: %p\n", p); 				// Pointer Return
	printf("Pointer Laenge: %d\n\n", i); */
}
