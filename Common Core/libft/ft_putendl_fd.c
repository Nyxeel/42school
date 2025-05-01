#include <unistd.h>

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	size_t i;

	i = 0;
	while(s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

int	main()
{
	char src[] = "Der Text zum durchleiten";
	int fd = 1;
	ft_putendl_fd(src, fd);
	return (0);
}