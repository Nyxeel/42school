/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:45:01 by pjelinek          #+#    #+#             */
/*   Updated: 2025/02/26 20:48:27 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_capitalize(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	ft_strlowcase(char d)
{
	int	i;

	i = 0;
	if (d >= 65 && d <= 90)
		d += 32;
	return (d);
}

char	ft_strupcase(char c)
{
	int	i;

	i = 0;
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	str[0] = ft_strupcase(str[0]);
	i = 1;
	while (str[i] != '\0')
	{
		if (ft_capitalize(str[i - 1]) == 0)
			str[i] = ft_strupcase(str[i]);
		else
			str[i] = ft_strlowcase(str[i]);
		i++;
	}
	return (str);
}
/*
int	main(void)
{
    char src[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

    printf("Vorher: %s\n", src);
	printf("Neuer Text: %s", ft_strcapitalize(src));
	
}*/
