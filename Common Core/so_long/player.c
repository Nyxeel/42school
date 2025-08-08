/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:27:04 by pjelinek          #+#    #+#             */
/*   Updated: 2025/08/08 11:17:40 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_up(t_data *game)
{
	int	height;
	int	width;

	void *black = mlx_new_image(game->mlx.connect, TILE_SIZE, TILE_SIZE);
	if (!black)
		exit_mlx(game, "mlx black image not found");
	mlx_put_image_to_window(game->mlx.connect, game->mlx.win, black, game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
	mlx_destroy_image(game->mlx.connect, black);	
	mlx_destroy_image(game->mlx.connect, game->mlx.player_img);
	game->player.y -= 1;
	game->mlx.player_img = mlx_xpm_file_to_image(game->mlx.connect,
		"tile-set/character/up.xpm", &width, &height);
	if (!game->mlx.player_img)
		exit_mlx(game, "mlx player_up image not found");
	mlx_put_image_to_window(game->mlx.connect, game->mlx.win,
		game->mlx.player_img, game->player.x * TILE_SIZE,
		game->player.y * TILE_SIZE);

}
void	update_player_left(t_data *game)
{
	int	height;
	int	width;

	void *black = mlx_new_image(game->mlx.connect, TILE_SIZE, TILE_SIZE);
	if (!black)
		exit_mlx(game, "mlx black image not found");
	mlx_put_image_to_window(game->mlx.connect, game->mlx.win, black, game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
	mlx_destroy_image(game->mlx.connect, black);	
	mlx_destroy_image(game->mlx.connect, game->mlx.player_img);
	game->player.x -= 1;
	game->mlx.player_img = mlx_xpm_file_to_image(game->mlx.connect,
		"tile-set/character/left.xpm", &width, &height);
	if (!game->mlx.player_img)
		exit_mlx(game, "mlx player_left image not found");
	mlx_put_image_to_window(game->mlx.connect, game->mlx.win,
		game->mlx.player_img, game->player.x * TILE_SIZE,
		game->player.y * TILE_SIZE);

}

void	update_player_down(t_data *game)
{
	int	height;
	int	width;

	void *black = mlx_new_image(game->mlx.connect, TILE_SIZE, TILE_SIZE);
	if (!black)
		exit_mlx(game, "mlx black image not found");
	mlx_put_image_to_window(game->mlx.connect, game->mlx.win, black, game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
	mlx_destroy_image(game->mlx.connect, black);	
	mlx_destroy_image(game->mlx.connect, game->mlx.player_img);	
	game->player.y += 1;
	game->mlx.player_img = mlx_xpm_file_to_image(game->mlx.connect,
		"tile-set/character/down.xpm", &width, &height);
	if (!game->mlx.player_img)
		exit_mlx(game, "mlx player_down image not found");
	mlx_put_image_to_window(game->mlx.connect, game->mlx.win,
		game->mlx.player_img, game->player.x * TILE_SIZE,
		game->player.y * TILE_SIZE);

}

void	update_player_right(t_data *game)
{
	int	height;
	int	width;

	void *black = mlx_new_image(game->mlx.connect, TILE_SIZE, TILE_SIZE);
	if (!black)
	exit_mlx(game, "mlx black image not found");
	mlx_put_image_to_window(game->mlx.connect, game->mlx.win, black, game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
	mlx_destroy_image(game->mlx.connect, black);	
	if(game->mlx.player_img)
		mlx_destroy_image(game->mlx.connect, game->mlx.player_img);
	game->player.x += 1;
	game->mlx.player_img = mlx_xpm_file_to_image(game->mlx.connect,
		"tile-set/character/right.xpm", &width, &height);
	if (!game->mlx.player_img)
		exit_mlx(game, "mlx player_right image not found");
	mlx_put_image_to_window(game->mlx.connect, game->mlx.win,
		game->mlx.player_img, game->player.x * TILE_SIZE,
		game->player.y * TILE_SIZE);

}


void	update_game(t_data *game, char id)
{
	if (id == 'u' && (game->map[game->player.y - 1][game->player.x]) != '1')
		update_player_up(game);
	else if (id == 'l' && (game->map[game->player.y][game->player.x - 1]) != '1')
		update_player_left(game);
	else if (id == 'd' && (game->map[game->player.y + 1][game->player.x]) != '1')
		update_player_down(game);
	else if (id == 'r' && (game->map[game->player.y][game->player.x + 1]) != '1')
		update_player_right(game);
	if (game->map[game->player.y - 1][game->player.x] == 'C' ||
		game->map[game->player.y][game->player.x - 1] == 'C' ||
		game->map[game->player.y + 1][game->player.x] == 'C' ||
		game->map[game->player.y][game->player.x + 1] == 'C' ||)
		game->coin_count--;
}

// cc mlx_init.c -lX11 -lXext -lmlx -lbsd -fsanitize=address,leak,undefined -g3

//
//cc player.c map_validation.c utils.c mlx_init.c create_game.c -lX11 -lXext -lmlx -lbsd -g3
