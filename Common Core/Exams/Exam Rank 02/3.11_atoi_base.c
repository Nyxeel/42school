/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.11_atoi_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:09:16 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/25 10:01:37 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int	isvalid(char c, int base)
{
	int i;

	i = 0;
	char *lcbase = "0123456789abcdef";
    char *ucbase = "0123456789ABCDEF";
	while (i < base)
	{
		if (c == lcbase[i] || c == ucbase[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int i;
	int minus;
	int nb;

	nb = 0;
	minus = 1;
	i = 0;

	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] && isvalid(str[i], str_base))
	{
		nb = nb * str_base;
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb + str[i] - '0';
		if (str[i] >= 'A' && str[i] <= 'Z')
			nb = nb + str[i] - 'A' + 10;
		if (str[i] >= 'a' && str[i] <= 'z')
			nb = nb + str[i] - 'a' + 10;
		i++;
	}
	return (nb * minus);
}

int	main(int ac, char **av)
{
 	if (ac == 2)
 	{
 		printf("%d", ft_atoi_base(av[1], 16));
 		return (0);
 	}
}




