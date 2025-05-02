/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:50:02 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/02 17:50:29 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count]) 
		count++;
	return (count);
}

int	main(void)
{
	char src[] = "aaaabbbbccccddddee";

	printf("Count: %zu", ft_strlen(src));
}
