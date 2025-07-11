#include "libunit.h"

int	cmp_sizet(size_t n1, size_t n2)
{
	if (n1 == n2)
		return (0);
	else
		return (-1);
}

int	cmp_ssizet(ssize_t n1, ssize_t n2)
{
	if (n1 == n2)
		return (0);
	else
		return (-1);
}

int	cmp_int(int n1, int n2)
{
	if (n1 == n2)
		return (0);
	else
		return (-1);
}

int	cmp_long(long n1, long n2)
{
	if (n1 == n2)
		return (0);
	else
		return (-1);
}
