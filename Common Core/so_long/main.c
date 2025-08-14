/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:15:57 by netrunner         #+#    #+#             */
/*   Updated: 2025/08/14 17:56:43 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void	exit_call(char *message, char **split, t_data *game)
{
	if (message)
	{
		write(2, "Error\n", 6);
		write(2, message, ft_strlen(message));
		if (split)
			ft_freeall(split, count_lines(split));
		free(game);
		exit(1);
	}
	else
	{
		if (split)
			ft_freeall(split, count_lines(split));
		free(game);
		exit(0);
	}
}

static void	check_map(char *map_path, t_data *game)
{
	game->map = extract_map(map_path);
	if (!game->map)
		exit_call("Map extraction failed\n", game->map, game);
	if (!check_doubles(game))
		exit_call("Doubles found (P, E)\n", game->map, game);
	if (!check_forbidden_chars(game))
		exit_call("Forbidden char detected\n", game->map, game);
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

static bool	check_map_string(char *str, char c)
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

int	main(int ac, char **av)
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
		write(2, "No valid map found!", 21);
	free(game);
	return (0);
}
