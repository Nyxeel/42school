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



#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_vars
{
    void    *mlx;
    void    *win;
}    t_vars;

// int    close (int keycode, t_varsvars)
// {
//     mlx_destroy_window(vars->mlx, vars->win);
//     return (0);
// }

int    handle_input(int keysym, t_vars *vars)
{
    if (keysym == 65307)
    {
        printf("The key you pressed: %d\n", keysym);
        mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
    	free(vars->mlx);
		exit(0);

    }
    printf("The key you pressed: %d\n", keysym);
	 return (0);
}

int main(void)
{
    t_vars    vars;

    vars.mlx = mlx_init();
    if (!vars.mlx)
        return (0);
    vars.win = mlx_new_window(vars.mlx, 300, 300, "I forgor coding");
    if (!vars.win)
    {
        free(vars.win);
        return (0);
    }
    mlx_key_hook(vars.win, &handle_input, &vars);
    mlx_loop(vars.mlx);
    mlx_destroy_display(vars.mlx);
    free(vars.mlx);
}
