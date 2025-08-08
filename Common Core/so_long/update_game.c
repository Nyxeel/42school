/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:27:04 by pjelinek          #+#    #+#             */
/*   Updated: 2025/08/08 17:27:19 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_move_counter(t_data *game)
{
	char	*move_count;
	void	*black_img;
	int		height;
	int		width;

	move_count = ft_itoa(game->move_count);
	black_img = mlx_xpm_file_to_image(game->mlx.connect,
			"tile-set/black64x64.xpm", &width, &height);
	if (!black_img)
		exit_mlx(game, "mlx black image not found");
	mlx_put_image_to_window(game->mlx.connect, game->mlx.win,
		black_img, 64 + (game->length.x * TILE_SIZE / 2),
		(game->length.y) * TILE_SIZE);
	mlx_destroy_image(game->mlx.connect, black_img);
	mlx_string_put(game->mlx.connect, game->mlx.win,
		game->length.x * TILE_SIZE / 2,
		(game->length.y + 0.6) * TILE_SIZE, WHITE, "MOVEMENTS:");
	mlx_string_put(game->mlx.connect, game->mlx.win,
		game->length.x * TILE_SIZE / 2 + 70,
		(game->length.y + 0.6) * TILE_SIZE, WHITE, move_count);
	free(move_count);
}

void	update_player_coords(t_data *game, char id)
{
	if (id == 'u')
		game->player.y += -1;
	if (id == 'l')
		game->player.x += -1;
	if (id == 'd')
		game->player.y += 1;
	if (id == 'r')
		game->player.x += 1;
}

char	*get_img_path(char id)
{
	char	*path;

	if (id == 'u')
		path = "tile-set/character/up.xpm";
	if (id == 'l')
		path = "tile-set/character/left.xpm";
	if (id == 'd')
		path = "tile-set/character/down.xpm";
	if (id == 'r')
		path = "tile-set/character/right.xpm";
	return (path);
}

void	update_player(t_data *game, char id)
{
	int		height;
	int		width;
	void	*black_img;

	black_img = mlx_new_image(game->mlx.connect, TILE_SIZE, TILE_SIZE);
	if (!black_img)
		exit_mlx(game, "mlx black_img not found");
	mlx_put_image_to_window(game->mlx.connect, game->mlx.win,
		black_img, game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
	mlx_destroy_image(game->mlx.connect, black_img);
	update_player_coords(game, id);
	game->mlx.player_img = mlx_xpm_file_to_image(game->mlx.connect,
			get_img_path(id), &width, &height);
	if (!game->mlx.player_img)
		exit_mlx(game, "mlx player_img not found");
	mlx_put_image_to_window(game->mlx.connect, game->mlx.win,
		game->mlx.player_img, game->player.x * TILE_SIZE,
		game->player.y * TILE_SIZE);
	mlx_destroy_image(game->mlx.connect, game->mlx.player_img);
	game->move_count += 1;
	add_move_counter(game);
	printf("Movements: %i\n", game->move_count);///////////////////////////////////
	printf("COINS: %i\n", game->coin_count);

}

void	update_game(t_data *game, char id)
{
	if (id == 'u' && (game->map[game->player.y - 1][game->player.x]) != '1')
		update_player(game, id);
	else if (id == 'l' && (game->map[game->player.y][game->player.x - 1]) != '1')
		update_player(game, id);
	else if (id == 'd' && (game->map[game->player.y + 1][game->player.x]) != '1')
		update_player(game, id);
	else if (id == 'r' && (game->map[game->player.y][game->player.x + 1]) != '1')
		update_player(game, id);
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->map[game->player.y][game->player.x] = '0';
		game->coin_count -= 1;
	}
	if (game->coin_count == 0 && game->player.y == game->exit.y
			&& game->player.x == game->exit.x)
	{
		write(1, "You won the game!", 17);
		exit_mlx(game, NULL);
	}

}

// cc mlx_init.c -lX11 -lXext -lmlx -lbsd -fsanitize=address,leak,undefined -g3

//
//cc player.c map_validation.c utils.c mlx_init.c create_game.c -lX11 -lXext -lmlx -lbsd -g3
