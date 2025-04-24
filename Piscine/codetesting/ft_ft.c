#include <unistd.h>
#include <stdio.h>

void	ft_ft(int* nbr)
{
	*nbr = 42;
	
	printf("Pointer Adress:%p \n", nbr);
	printf("Pointer Value :%i", *nbr);
}


int	main(void)
{
	int x;
	
	x = 0;
	ft_ft(&x);
}

