/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:50:02 by pjelinek          #+#    #+#             */
/*   Updated: 2025/06/07 00:47:48 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;
	if (!str)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}
/*
int	main(void)
{
	char src[] = "aaaabbbbccccddddee";

	printf("Count: %zu", ft_strlen(src));
} */
