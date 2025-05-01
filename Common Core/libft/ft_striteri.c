#include <stdio.h>

static void ft_chchr(unsigned int index, char *str)
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
		ft_chchr(i, &s[i]);
		i++;
	}

}

int	main(void)
{
	char src[] = "Der manipulierende Text"; 	// "*****anipulierende Text";
	
	ft_striteri(src, ft_chchr);
	printf("%s", src);
}