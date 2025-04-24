/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:59:40 by pjelinek          #+#    #+#             */
/*   Updated: 2025/02/07 20:04:44 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	main(void)
{
	char arr[50];
	int  es;

	printf("Type a word with 's'! max. 40 chars\n");
	scanf("%49s", arr);
	
	
	printf("\n--LOADING--!\n\n");
	sleep(1);
	
	int length = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i <= length; i++)
  		{

				if (arr[i] == 's' || arr[i] == 'S')
					{	
						printf("Found S at %i. Column", i+1);
						es = 1;
						break;	
					}

		}
	if (es != 1)
		printf("No S found in your word");
}
