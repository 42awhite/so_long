/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:59:23 by ablanco-          #+#    #+#             */
/*   Updated: 2023/02/16 18:21:54 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	// la ruta tienes que obtener por parametros obtenidos en el main.
	t_sl	sl;

	if (argc == 1)
		return (1);
	ft_check_all_map(&sl, argv[1]);
	sl.vars.mlx = mlx_init();
	sizexy_win(&sl.map);
	sl.vars.win = mlx_new_window(sl.vars.mlx, sl.map.size.x_win, sl.map.size.y_win, "I'm a SEXY window!! :)");
	load_imgs(&sl.img, &sl.vars);
	img_to_map(&sl.img, &sl.vars, &sl.map);
	mlx_key_hook(sl.vars.win, ft_input, &sl);
	mlx_hook(sl.vars.win, 17, 0, ft_close, &sl.vars);
	mlx_loop(sl.vars.mlx);
}