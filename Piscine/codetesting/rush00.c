/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:43:18 by pjelinek          #+#    #+#             */
/*   Updated: 2025/02/08 15:25:41 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
////#include "ft_putchar.c"


void	matrix(int a, int b)
{
	int len;
	int hei;
	char A;
	char B;
	char C;
	int h;
	int i;


	len = a-2;
	hei = b-2;
	A = 'A';
	B = 'B';
	C = 'C';
	i = 1;



////////////////////////////////////////////////////////////////////////////
	
//Line First


	write(1, &A, 1); 
		while (i <= len)
			{
				write(1, &B, 1);
				i++;
			}

	write(1, &A, 1);
	write(1, "\n", 1);


////////////////////////////////////////////////////////////////////////
	
//Line hei b - 2 |||||| INPUT WHILE LOOP AND REPEAT 'hei' times


	i = 1;		
			while (i <= hei)
			{	
				write(1, &B, 1); 
				
				h = 1;

				while (h <= len)	
					{
						write(1, " ", 1);
						h++;
					}	
				
					 
				write(1, &B, 1);
				write(1, "\n", 1);
				i++;
			}

			
/////////////////////////////////////////////////////////////////////////

//Line last
	i = 1;
	
	write(1, &C, 1); 
		
		while(i<=len)
			{
					write(1, &B, 1);
				  	i++;
			}

	write(1, &C, 1);
	write(1, "\n", 1);
////////////////////////////////////////////////////////////////////////
	
	
}




int	main(void)
{		
	float x;
	float y;

	printf("Type X Coordinate: \n"); 
	scanf("%f", &x);					//// INPUT DECIMAL SHOW ERROR MESSAGE

	printf("Type Y Coordinate: \n");
	scanf("%f", &y);					//// DECIMAL INPUT SHOW ERROR MESSAGE

	matrix(x , y);
}
