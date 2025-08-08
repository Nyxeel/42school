/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:15:57 by netrunner         #+#    #+#             */
/*   Updated: 2025/08/08 00:13:11 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	count_lines(char **split)
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

void	exit_call(char *message, char **split, t_data *game)
{
	write(2, "Error: ", 7);
	write(2, message, ft_strlen(message));
	if (split)
		ft_freeall(split, count_lines(split));
	free(game);
	exit(1);
}


char	**extract_map(char *map_path)
{
	int		i;
	char	*line;
	int		bytes;
	char	**map;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (!line)
		return (close(fd), NULL);
	bytes = read(fd, line, BUFFER_SIZE);
	if (bytes <= 0)
		return (close(fd), free(line), NULL);
	line[bytes] = '\0';
	map = ft_split(line, '\n');
	if (!map)
		return (close(fd), free(line), NULL);
	return (close(fd), free(line), map);
}

void  flood_fill(t_data *game, int x, int y)
{
	int	i;
	
	i = 0;
	if (x < 0 || y < 0 || x >= game->length.x || y >= game->length.y)
		return ;
	if (game->map[y][x] == '1' || game->map[y][x] == 'X')
		return ;
	else
	{
		game->map[y][x] = 'X';
		flood_fill(game, x + 1, y);
		flood_fill(game, x - 1, y);
		flood_fill(game, x, y + 1);
		flood_fill(game, x, y - 1);
	}
}

int	check_walls(char **map, t_data *game)
{
	int	i;

	i = 0;
	game->length.y = count_lines(map) - 1;
	while (map[i])
	{
		if (i == 0 || i == game->length.y)
		{
			if (ft_strcheck(map[i++], '1'))
				continue ;
			else
				return (0);
		}
		else
		{
			if (map[i][0] == '1' && map[i++][game->length.x] == '1')
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

bool	check_doubles(t_data *game)
{
	int		i;
	t_bool	_bool;

	_bool = (t_bool){0};
	i = 0;
	while (game->map[i])
	{
		if (find_char(game->map[i], 'P'))
		{
			if (!_bool.player && find_doubles(game->map[i], 'P') == 1)
				_bool.player = true;
			else
				return (false);
		}
		if (find_char(game->map[i], 'E'))
		{
			if (!_bool.exit && find_doubles(game->map[i], 'E') == 1)
				_bool.exit = true;
			else
				return (false);
		}
		i++;
	}
	return (true);
}

void	set_coords(bool *env, t_coord *point, int y, int x)
{
	(*point).x = x;
	(*point).y = y;
	*env = true;
}

int	check_letters_on_map(t_data *game)
{
	t_bool	_bo;
	int		i;

	_bo = (t_bool){0};
	i = 0;
	while (game->map[i])
	{
		if (find_char(game->map[i], 'P'))
			set_coords(&_bo.player, &game->player, i,
				find_char(game->map[i], 'P'));
		if (find_char(game->map[i], 'C'))
		{
			game->coin_count = find_doubles(game->map[i], 'C');
			_bo.coins = true;
		}
		if (find_char(game->map[i], 'E'))
			set_coords(&_bo.exit, &game->exit, i, find_char(game->map[i], 'E'));
		i++;
	}
	if (_bo.player == true && _bo.exit == true && _bo.coins == true)
		return (1);
	else if (_bo.player == false && _bo.exit == false && _bo.coins == false)
		return (0);
	return (-1);
}

void	check_map(char *map_path, t_data *game)
{
	int i = 0;
	game->map = extract_map(map_path);
	if (!game->map)
		exit_call("Map extraction failed\n", game->map, game);
	if (!check_doubles(game))
		exit_call("Doubles found (P, E)\n", game->map, game);
	if (check_letters_on_map(game) <= 0)
		exit_call("Letters failed (C,P,E,B)\n", game->map, game);
	game->length.x = ft_strlen(game->map[0]) - 1;
	if (!check_rectangular(game->map, game->length.x + 1))
		exit_call("Map is not rectangular\n", game->map, game);
	if (!check_walls(game->map, game))
		exit_call("Map not proper walled\n", game->map, game);
	flood_fill(game, game->player.x, game->player.y);
	if (check_letters_on_map(game))
		exit_call("Exit/Coins not reachable\n", game->map, game);
	ft_freeall(game->map, count_lines(game->map));
}

bool	check_map_string(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] == '.')
			return (false);
		i++;
	}
	return (true);
}

int main(int ac, char **av)
{
	t_data	*game;

	game = ft_calloc(1, sizeof(t_data));
	if (!game)
		return (0);
	if (ac == 2 && check_map_string(av[1], '/'))
	{
		check_map(av[1], game);
		mlx_initialize(av[1], game);
	}
	else
		write(2, "Error, no map found!", 21);
	free(game);
	return (0);
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
