/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:37:18 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/02 11:42:45 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit(int str)
{
	if (str >= 0 && str <= 9)
			return (1);
	return	(0); 
}
int	ft_isalpha(int str)
{
	if ((str >= 97 && str <= 122) || (str >= 65 && str <= 90))
		return (1);
	return	(0); 
}
int	ft_isalnum (int str)
{
	if ((ft_isalpha(str) || ft_isdigit(str)))
			return (1);
	return	(0); 
}

int	main(void)
{
	int a = 65;
	int b = '&';
	int c = '5';

	printf("%d\n", ft_isalnum(a));
	printf("%d\n", ft_isalnum(b));
	printf("%d", ft_isalnum(c));
}