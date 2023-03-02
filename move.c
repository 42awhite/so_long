/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:49:43 by ablanco-          #+#    #+#             */
/*   Updated: 2023/03/02 16:22:18 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(t_sl *sl, int dx, int dy)
{
	static long int	cont = 0;

	if ((sl->map.full_map[sl->pj.y_pj + dy][sl->pj.x_pj + dx] != '1'))
	{
		sl->map.full_map[sl->pj.y_pj][sl->pj.x_pj] = '0';
		if (sl->map.full_map[sl->pj.y_pj + dy][sl->pj.x_pj + dx] == 'C')
			sl->obj.col--;
		if (sl->map.full_map[sl->pj.y_pj + dy][sl->pj.x_pj + dx] == 'M')
			exit(0);
		sl->map.full_map[sl->pj.y_pj + dy][sl->pj.x_pj + dx] = 'P';
		sl->pj.x_pj += dx;
		sl->pj.y_pj += dy;
		img_to_map(sl);
		cont++;
		ft_putnbr(cont);
		ft_char('\n');
	}
	if (sl->pj.y_pj == sl->obj.y_ex
		&& sl->pj.x_pj == sl->obj.x_ex && sl->obj.col == 0)
		exit(0);
}

int	ft_input(int keycode, t_sl *sl)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 0 || keycode == 123)
	{
		sl->img.player = sl->img.pj_l;
		ft_move(sl, -1, 0);
	}
	if (keycode == 2 || keycode == 124)
	{
		sl->img.player = sl->img.pj_r;
		ft_move(sl, 1, 0);
	}
	if (keycode == 13 || keycode == 126)
	{
		sl->img.player = sl->img.pj_up;
		ft_move(sl, 0, -1);
	}
	if (keycode == 1 || keycode == 125)
	{
		sl->img.player = sl->img.pj_d;
		ft_move(sl, 0, 1);
	}
	return (0);
}
