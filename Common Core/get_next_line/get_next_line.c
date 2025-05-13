/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:43:08 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/13 18:58:06 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1

#include <fcntl.h>   // open
#include <stdlib.h>  // free
#include <stdio.h>   // printf


char *get_next_line(int fd)
{
	int			bytes;
	char static	*brain;
	int static	index;

	bytes = 0;
	while (brain[BUFFER_SIZE - 1] == '\n')
	{
		brain[BUFFER_SIZE] = read(fd, BUFFER_SIZE);
		index++;
	}



		return (strdup("Zeile5")) --> malloc - Rückgabe
}



Read liest in Buffer bis \n
static char *brain;
speichert aktuelle line in static char *brain.

substring von start bis inklusive \n extrahiert die
aktuelle Zeiile und returned diese


int	main(void)
{
	int fd = open("aot.txt", O_RDONLY);
	if (fd == -1)
		return (NULL);

	int i = 1;
	char *line;

	while ((line = get_next_line(fd)))
	{
		if (i == 5)
		{
			printf("Zeile 5: %s", line);
			free(line);
			break;
		}
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
#endif
