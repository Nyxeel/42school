/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:00:59 by pjelinek          #+#    #+#             */
/*   Updated: 2025/08/06 20:58:43 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>

int	keyhandler(int keysym, t_mlx *_mlx)
{
	if (keysym == ESC)
	{
		mlx_destroy_window(_mlx->connect, _mlx->win);
		mlx_destroy_display(_mlx->connect);
		free(_mlx->connect);
		exit(0);
	}
	printf("test %d\n", keysym);
	return (0);




}
int	main(void)
{
	t_mlx	_mlx;
	int	keysym;

	_mlx.width = 800;
	_mlx.height = 800;
	_mlx.connect = mlx_init();
	if (!_mlx.connect)
		exit(1);
	_mlx.win = mlx_new_window(_mlx.connect, _mlx.width, _mlx.height, "GAME");
	if (!_mlx.win)
	{
		mlx_destroy_display(_mlx.connect);
		free(_mlx.connect);
		exit(1);
	}

	//_mlx_hook(_mlx.connect,)
	mlx_key_hook(_mlx.win, keyhandler, &_mlx);



	mlx_loop(_mlx.connect);
	printf("test %d", keysym);
	//_mlx_destroy_window(_mlx.connect, _mlx.win);
	mlx_destroy_display(_mlx.connect);
	free(_mlx.connect);

	//_mlx_put_image_to_window(_mlx, win, img, x * TILE_SIZE, y * TILE_SIZE);





}
