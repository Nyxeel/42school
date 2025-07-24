/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.3_ft_range.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:02:53 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/23 16:50:09 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int	*ft_range(int start, int end)
{
	int	i;
	int	*arr;
	int	len;

	i = 0;
	if (end - start < 0)
		len = (end - start) * (-1) + 1;
	else
		len = end - start + 1;
	arr = malloc(len * sizeof(int));
	if (!arr)
		return (0);
	while (i < len)
	{
		if (start < end)
			arr[i] = start++;
		else
			arr[i] = start--;
		i++;
	}
	return (arr);
}

int	main(int ac, char **av)
{
	ft_range(1, 3);
}
