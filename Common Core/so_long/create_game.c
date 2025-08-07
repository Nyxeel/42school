/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:27:04 by pjelinek          #+#    #+#             */
/*   Updated: 2025/08/07 21:31:28 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>

void	add_img_walls(t_data *game)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = 0;
	j = 0;
	game->mlx.img_wall = mlx_xpm_file_to_image(game->mlx.connect,
			"tile-set/wall64x64.xpm", &width, &height);
	if (!game->mlx.img_wall)
		exit_call("img_wall failed", game->map, game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx.connect, game->mlx.win, game->mlx.img_wall,
					j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	add_player(t_data *game)
{
	int	width;
	int	height;

	game->mlx.player = mlx_xpm_file_to_image(game->mlx.connect,
			"tile-set/character/down.xpm", &width, &height);
	if (!game->mlx.player)
		exit_call("img_wall failed", game->map, game);
	mlx_put_image_to_window(game->mlx.connect, game->mlx.win,
		game->mlx.player, game->player.y * TILE_SIZE,
		game->player.x * TILE_SIZE);

}


void	create_map(t_data *game)
{
	add_img_walls(game);
	add_player(game);


	mlx_string_put(game->mlx.connect, game->mlx.win, game->length.x * TILE_SIZE / 2, (game->length.y + 0.6) * TILE_SIZE, 0xFFFFFF,"MOVEMENTS:");

	mlx_string_put(game->mlx.connect, game->mlx.win, game->length.x * TILE_SIZE / 2 + 70, (game->length.y + 0.6) * TILE_SIZE, 0xFFFFFF, "120");

}


// cc game->mlx_init.c -lX11 -lXext -lgame->mlx -lbsd -fsanitize=address,leak,undefined -g3

//
// cc map_validation.c utils.c game->mlx_init.c create_game.c -lX11 -lXext -lgame->mlx -lbsd -g3
