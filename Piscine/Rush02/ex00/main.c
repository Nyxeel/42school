/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhegewal <linus.hegewald8@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:31:10 by lhegewal          #+#    #+#             */
/*   Updated: 2025/02/23 22:37:33 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 4096

int	split_to_blocks(char *dict, char *str, char **dest);

void	put_str(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != 0)
	{
		write (1, &str[counter], 1);
		counter++;
	}
}
void	ft_error(int c)
{
	if (c == 1)
		write(2, "Error\n", 6);
	if (c == 2)
		write(2, "Dict Error", 10);
}

char	*open_files(const char *filename)
{
	int 	fd;
	char	*buffer;
	ssize_t	bytes;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_error(1);
		return (NULL);
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		ft_error(1);
		close(fd);
		return (NULL);
	}
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == -1)
	{
		ft_error(1);
		free(buffer);
		close(fd);
		return (NULL);
	}
	buffer[bytes] = '\0';
	close(fd);
	return (buffer);
}

int	ft_number_check(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (!(c[i] >= '0' && c[i] <= '9') || (c[0] == '0' && c[1] >= '0'
				&& c[1] <= '9'))
		{
			ft_error(1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*content;
	int		error;
	char	**dest;
//	char	*tmp;	
//	char	str;


	dest = malloc(sizeof(char *));
	*dest = malloc(sizeof(char));
	**dest = 0;
	error = 0;
	if (argc == 2)
	{
		if (ft_number_check(argv[1]))
		{	
			free(*dest);
			free(dest);
			return (1);
		}
		content = open_files("numbers.dict");
		if (!content)
		{
			free(*dest);
			free(dest);
			free(content);
			return (1);
		}
		error = split_to_blocks(content, argv[1], dest);
		if (error == -1)
		{	
			free(content);
			free(*dest);
			free(dest);
			return (1);
		}
	}
	else if (argc == 3)
	{
		if (ft_number_check(argv[2]))
		{	free(*dest);
			free(dest);
			return (1);
			}
		content = open_files(argv[1]);
		if (!content)
		{
			free(*dest);
			free(dest);
			free(content);
			return (1);
		}
		error = split_to_blocks(content, argv[2], dest);
		if (error == -1)
		{	
			free(*dest);
			free(dest);
			free(content);
			return (1);
		}
	}
	else
	{
		free(*dest);
		free(dest);
		ft_error(1);
		return (1);
	}
	put_str(*dest);
	put_str("\n");
	free(content);
	free(*dest);
	free(dest);
	return (0);
}
