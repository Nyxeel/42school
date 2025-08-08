/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:27:04 by pjelinek          #+#    #+#             */
/*   Updated: 2025/08/08 10:48:18 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>

void	add_wall_img(t_data *game)
{
	int	x;
	int	y;
	int	width;
	int	height;

	y = 0;
	x = 0;
	game->mlx.wall_img = mlx_xpm_file_to_image(game->mlx.connect,
			"tile-set/wall64x64.xpm", &width, &height);
	if (!game->mlx.wall_img)
		exit_mlx(game, "mlx wall image not found");
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx.connect, game->mlx.win, game->mlx.wall_img,
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx.connect, game->mlx.wall_img);
}

void	add_coins(t_data *game)
{
	int	x;
	int	y;
	int	width;
	int	height;

	y = 0;
	x = 0;
	game->mlx.coin_img = mlx_xpm_file_to_image(game->mlx.connect,
			"tile-set/character/right.xpm", &width, &height);
	if (!game->mlx.wall_img)
		exit_mlx(game, "mlx wall image not found");
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx.connect, game->mlx.win, game->mlx.coin_img,
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx.connect, game->mlx.coin_img);
}


void	add_player(t_data *game)
{
	int	width;
	int	height;

	game->mlx.player_img = mlx_xpm_file_to_image(game->mlx.connect,
			"tile-set/character/down.xpm", &width, &height);
	if (!game->mlx.player_img)
		exit_mlx(game, "mlx player image not found");
	mlx_put_image_to_window(game->mlx.connect, game->mlx.win,
		game->mlx.player_img, game->player.x * TILE_SIZE,
		game->player.y * TILE_SIZE);

}


void	create_map(t_data *game)
{
	add_wall_img(game);
	add_player(game);
	add_coins(game);
	mlx_string_put(game->mlx.connect, game->mlx.win, game->length.x * TILE_SIZE / 2, (game->length.y + 0.6) * TILE_SIZE, 0xFFFFFF,"MOVEMENTS:");
	mlx_string_put(game->mlx.connect, game->mlx.win, game->length.x * TILE_SIZE / 2 + 70, (game->length.y + 0.6) * TILE_SIZE, 0xFFFFFF, "120");

}


// cc game->mlx_init.c -lX11 -lXext -lgame->mlx -lbsd -fsanitize=address,leak,undefined -g3

//
// cc map_validation.c utils.c game->mlx_init.c create_game.c -lX11 -lXext -lgame->mlx -lbsd -g3
