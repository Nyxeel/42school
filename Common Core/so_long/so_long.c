/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:15:57 by netrunner         #+#    #+#             */
/*   Updated: 2025/08/05 20:47:51 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	grid_line_count(char **split)
{
	int	count;

	count = 0;
	if (split || *split)
	{
		while (split[count] != NULL)
		count++;
	}
	return (count);
}

void	exit_call(char *message, char **split)
{
	write(2, "Error: ", 7);
	write(2, message, ft_strlen(message));
	if (split || *split)
	ft_freeall(split, grid_line_count(split));
	exit(1);
}

void	free_function(char **p)
{
	if (!*p)
	return ;
	free(*p);
	*p = NULL;
}

char	**parse_input(int fd)
{
	int		i;
	char	*line;
	int		bytes;
	char	**map;

	line = (char *)ft_calloc(1, BUFFER_SIZE + 1);
	if (!line)
	return (0);
	bytes = read(fd, line, BUFFER_SIZE);
	if (bytes < 0)
	return (free_function(&line), NULL);
	if (bytes == 0)
	return (free_function(&line), NULL);
	line[bytes] = '\0';
	map = ft_split(line, '\n');
	if (!map)
	return (free_function(&line), NULL);
	free(line);
	return (map);
}

void  flood_fill(char **map, t_coord length, t_coord begin)
{
	int	x;
	int y;

	if ()
}

int	check_walls(char **grid, t_data *game)
{
	int	i;

	i = 0;
	game->length.y = grid_line_count(grid);
	while (grid[i])
	{
		if (i == 0 || i == game->length.y - 1)
		{
			if (ft_strcheck(grid[i++], '1'))
			continue ;
			else
			return (0);
		}
		else
		{
			if (grid[i++][0] == '1' && grid[i][game->length.x - 1])
				continue ;
			else
				return (0);
		}
	}
	return (1);
}

int	check_rectangular(char **map, int line_length)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i++]) == line_length)
			continue ;
		else
			return (0);
	}
	return (1);
}

void	check_map(char *map_path, t_data *_game)
{
	int		fd;
	int		line_length;

	fd = open(map_path, O_RDONLY);
	if (fd == EOF)
		exit_call("Nothing found - Check path again", _game->map);
	if (fd == 0)
		exit_call("Map file empty", _game->map);
	_game->map = parse_input(fd);
	if (!_game->map)
		exit_call("Map parsing failed", _game->map);
	_game->length.x = ft_strlen(_game->map[0]);
	if (!check_rectangular(_game->map, _game->length.x))
		exit_call("Map is not rectangular", _game->map);
	if (!check_walls(_game->map, _game))
		exit_call("Map not proper walled", _game->map);
	if (!flood_fill(_game->map, _game->length, _game->length))
		exit_call("Floodfill failed", _game->map);

	printf("OK");
}


int main(int ac, char **av)
{
	t_data	*_game;
	_game = ft_calloc(1, sizeof(t_data));
	if (ac == 2)
		check_map(av[1], _game);
	else
		write(2, "Error, no map found!", 21);
}

/* int main(void)
{
	char **area;
	t_point grid;
	t_point start_point;

	void *mlx = mlx_init();

	void *win = mlx_new_window(mlx, width, height, "so_long");

	int img_width, img_height;
	void *img = mlx_xpm_file_to_image(mlx, "path/to/file.xpm", &img_width, &img_height);

	mlx_put_image_to_window(mlx, win, img, x * TILE_SIZE, y * TILE_SIZE);




	validate_map()
	print_tab(area);
	flood_fill(area, size, begin);
	putc('\n');
	print_tab(area);
	return (0);
} */



/*
	ALLOWED FUNCTIONS:

	open, close, read, write,
	malloc, free, perror,
	strerror, exit

	•All functions of the math
	library (-lm compiler option,
	man man 3 math)

	•All functions of the MiniLibX





CHECK LINE 1 and Last LINE are alle "1",
Check the lines intbetween have at index 1 and last index "1"



•You must verify if there is a valid path in the map.

-FLOODFILL all "0" "C" "P" "C" ;

•You must be able to parse any kind of map, as long as it respects the above rules.

Open map and read it!
	open();
	read();


 */
