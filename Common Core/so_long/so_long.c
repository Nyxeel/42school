/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:15:57 by netrunner         #+#    #+#             */
/*   Updated: 2025/08/05 11:55:21 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void  flood_fill(char **tab, t_point size, t_point begin)
{

}


int main(void)
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
}


/* Prüfe, ob die Map rechteckig ist
(jede Zeile gleich lang!)

Prüfe, ob die Map komplett von '1' (Walls) umschlossen ist

Prüfe, ob alle Ziele erreichbar sind
(z.B. ob von 'P' aus zu allen 'C' und zum 'E' ein Pfad existiert) */