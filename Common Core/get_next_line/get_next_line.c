


char *get_next_line(int fd)
{
	int 	bytes;
	char 	*buffer;

	bytes = 0;
	while (!\n && read == true)
		buffer[bytes] = read(fd, BUFFER_SIZE);



		return (strdup("Zeile5")) --> malloc - Rückgabe
}

#include <fcntl.h>   // open
#include <stdlib.h>  // free
#include <stdio.h>   // printf

int	main(void)
{
	int fd = open("anime.txt", O_RDONLY);
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
