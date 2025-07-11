#include "libunit.h"

int	cmp_strs(char *str1, char *str2)
{
	size_t	len1;
	size_t	len2;

	if (!str1 || !str2)
		return (-1);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 != len2)
		return (-1);
	if (ft_strncmp(str1, str2, len1) != 0)
		return (-1);
	return (0);
}
