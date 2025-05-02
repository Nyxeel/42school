/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:38:16 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/02 10:39:01 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isascii(int str)
{
	if (str >= 0 && str <= 127)
			return (1);
	return	(0); 
}

int	main(void)
{
	int a = 6;
	int b = 189;

	printf("%d\n", ft_isascii(a));
	printf("%d", ft_isascii(b));
}