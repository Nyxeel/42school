/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:27:04 by pjelinek          #+#    #+#             */
/*   Updated: 2025/08/07 21:40:55 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_up(t_data *game)
{
	int	height;
	int	width;

	mlx_destroy_image(game->mlx.connect, game->mlx.player);
	game->player.x -= 1;
	game->mlx.player = mlx_xpm_file_to_image(game->mlx.connect,
		"tile-set/character/up.xpm", &width, &height);
	if (!game->mlx.player)
		exit_call("img_wall failed", game->map, game);
	mlx_put_image_to_window(game->mlx.connect, game->mlx.win,
		game->mlx.player, game->player.y * TILE_SIZE,
		game->player.x * TILE_SIZE);

}

void	update_game(t_data *game, char id)
{
	if (id == 'u' && (game->map[game->player.y][game->player.x -1]) != '1')
		update_player_up(game);
	/*if (id == "l" && game->player.y - 1 != '1')
		update_player_left(game);
	if (id == "d" && game->player.y - 1 != '1')
		update_player_down(game);
	if (id == "r" && game->player.y - 1 != '1')
		update_player_right(game); */

}

// cc mlx_init.c -lX11 -lXext -lmlx -lbsd -fsanitize=address,leak,undefined -g3

//
// cc map_validation.c utils.c mlx_init.c create_game.c -lX11 -lXext -lmlx -lbsd -g3
