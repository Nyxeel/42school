/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game->mlxx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:00:59 by pjelinek          #+#    #+#             */
/*   Updated: 2025/08/06 20:58:43 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>

void exit_mlx(t_data *game, char *message)
{
	mlx_destroy_window(game->mlx.connect, game->mlx.win);
	mlx_destroy_display(game->mlx.connect);
	free(game->mlx.connect);
	exit_call(message, game->map, game);
}

int	keyhandler(int keysym, t_data *game)
{
	if (keysym == ESC)
		exit_mlx(game, NULL);
	if (keysym == W || keysym == UP)
		update_game(game, 'u');
 	if (keysym == A || keysym == LEFT)
		update_game(game, 'l');
	if (keysym == D || keysym == RIGHT)
		update_game(game, 'r');
	if (keysym == S || keysym == DOWN)
		update_game(game, 'd');
	return (0);
}

int close_window(t_data *game)
{
	exit_mlx(game, NULL);
	return (0);
}

void	init_game(t_data *game, char *map_path)
{
	//int i = 0;
	game->map = extract_map(map_path);
	if (!game->map)
		exit_call("Map extraction failed", game->map, game);
	game->length.x = ft_strlen(game->map[0]);
	game->length.y = count_lines(game->map);
	/* while (game->map[i])
		printf("%s\n", game->map[i++]); */
}

int	mlx_initialize(char *map_path, t_data *game)
{


	init_game(game, map_path);
	game->mlx.width = game->length.x * TILE_SIZE;
	game->mlx.height = (1 + game->length.y) * TILE_SIZE;
	game->mlx.connect = mlx_init();
	if (!game->mlx.connect)
		exit_call("mlx connect failed", game->map, game);
	game->mlx.win = mlx_new_window(game->mlx.connect, game->mlx.width, game->mlx.height, "GAME");
	if (!game->mlx.win)
	{
		mlx_destroy_display(game->mlx.connect);
		free(game->mlx.connect);
		exit_call("mlx window failed", game->map, game);
	}
	create_map(game);
	mlx_key_hook(game->mlx.win, keyhandler, game);
	mlx_hook(game->mlx.win, ON_DESTROY, STOP, close_window, game);
	mlx_loop(game->mlx.connect);
	return (0);
}


//  cc player.c utils.c map_validation.c create_game.c mlx_init.c -lX11 -lXext -lmlx -lbsd -fsanitize=address,leak,undefined -g3
// gcc -I./minilibx-linux

/*
gcc -I./minilibx-linux \
    player.c map_validation.c utils.c mlx_init.c create_game.c \
    -L./minilibx-linux -lmlx \
    -lXext -lX11 -lbsd -g3 */
