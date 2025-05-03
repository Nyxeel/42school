/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:36:44 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/03 11:26:53 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
    size_t i;
  	i = 0;
    unsigned char *arr = (unsigned char*) s;

	if(n <= 0)
		return NULL;
    while (i < n)
    {
        arr[i] = 0;
        i++;
    }
    return (scasdasd);
}

void *ft_calloc(size_t nmemb, size_t size)
{
    unsigned char *p;
	size_t total;

	total = nmemb * size;
	if (size != 0 && !(total / nmemb == size))
		return(malloc(1));
	p = malloc(total);
	if	(p == NULL)
		return(NULL);
	return (ft_bzero(p, total));
}

int	main(void)
{
	char elements[10];
	printf("elemnts: %zu\n", sizeof(elements));
	//printf("elemnts: %zu\n", elements);

	char *p = ft_calloc(10, sizeof(elements[0]));

	size_t i = 0;
	while (i < 10)
	{
		printf("elements[%zu]: %d\n", i, p[i]);
		i++;
	}
	free(p);
/*
	char elem[] = {'c', 'a', 'd', 'a', 'e'};
	int *s = ft_calloc(elem, 10);

	size_t len;
	size_t arr_size;
	size_t data_size;

	arr_size = sizeof(elem);
	data_size = sizeof(elem[0]);
	len = arr_size / data_size;

	i = 0;
	while (i < len)
	{
		printf("s[%zu]: %d\n", i, s[i]);
		i++;
	}
	free(s);*/
}
