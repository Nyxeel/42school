/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:27:04 by pjelinek          #+#    #+#             */
/*   Updated: 2025/08/29 15:58:18 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

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
