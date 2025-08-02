#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_isspace(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

void 	rotstring(char *str)
{

	int i = 0;
	int start;
	while (str[i] && str[i] <= 32)
		i++;
	start = i;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	int end = i - start;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		while (str[i] && !ft_isspace(str[i]) && !ft_isspace(str[i + 1]))
		{
			while (str[i] && !ft_isspace(str[i]))
			{
				write(1, &str[i], 1);
				i++;
			}
			write (1, " ", 1);
		}
	}
	write(1, &str[start], end);
}

int	main(int ac, char** av)
{
	int i;

	i = 1;
	if (ac == 2)
		rotstring(av[1]);
	write(1, "\n", 1);

}
