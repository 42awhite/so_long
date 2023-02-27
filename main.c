/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:59:23 by ablanco-          #+#    #+#             */
/*   Updated: 2023/02/27 16:57:50 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_anim(t_sl *sl)
{
	sl->c_tim++;
	if (sl->c_tim % 1000 == 0)
		ft_win(sl);
		//sl->c_tim = 0;
	//printf("\n%d\n", sl->c_tim);
	return(0);
}

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
	img_to_map(&sl);
	mlx_key_hook(sl.vars.win, ft_input, &sl);
	mlx_hook(sl.vars.win, 17, 0, ft_close, &sl.vars);
	sl.c_tim = 0;
	mlx_loop_hook(sl.vars.mlx, ft_anim, &sl);
	mlx_loop(sl.vars.mlx);
}