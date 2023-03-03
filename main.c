/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:59:23 by ablanco-          #+#    #+#             */
/*   Updated: 2023/03/03 18:12:27 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_anim(t_sl *sl)
{
	sl->c_tim++;
	if (sl->c_tim % 1000 == 0)
		ft_win(sl);
	return (0);
}

void	ft_check_all_map(t_sl *sl, char *path_map)
{
	ft_name_map(path_map);
	ft_memset(sl, 0, sizeof(t_sl));
	ft_count_lines(path_map, &sl->map.size);
	sl->map.full_map = ft_all_map(path_map, sl->map.size.y);
	if (sl->map.full_map == NULL)
		return ;
	sl->map.p_map = ft_all_map(path_map, sl->map.size.y);
	if (sl->map.p_map == NULL)
		return ;
	ft_border_map(sl->map.full_map, sl->map.size.x, sl->map.size.y);
	ft_check_obj(sl->map.full_map, sl);
	ft_p_map(sl->map.p_map, sl->pj.x_pj, sl->pj.y_pj);
	ft_valid_map(sl->map.p_map);
}

int	main(int argc, char **argv)
{
	t_sl	sl;

	if (argc == 1)
		return (1);
	ft_check_all_map(&sl, argv[1]);
	sl.vars.mlx = mlx_init();
	sizexy_win(&sl.map);
	sl.vars.win = mlx_new_window(sl.vars.mlx, sl.map.size.x_win,
			sl.map.size.y_win, "I'm a SEXY window!! :)");
	load_imgs(&sl.img, &sl.vars);
	img_to_map(&sl);
	mlx_key_hook(sl.vars.win, ft_input, &sl);
	mlx_hook(sl.vars.win, 17, 0, ft_close, &sl.vars);
	sl.c_tim = 0;
	mlx_loop_hook(sl.vars.mlx, ft_anim, &sl);
	mlx_loop(sl.vars.mlx);
}
