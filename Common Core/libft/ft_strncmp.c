/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:08:15 by pjelinek          #+#    #+#             */
/*   Updated: 2025/02/19 19:14:24 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	/*if (n == 0)
		return (0);*/
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

int	main(void)
{
	char src[] = "aaaacaba";
	char dest[] = "aaaaabcabcabb";
	unsigned int n = 0;

	int result = ft_strncmp(src, dest, n);
    	printf("Return: %d", result);
}
