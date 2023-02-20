/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:49:43 by ablanco-          #+#    #+#             */
/*   Updated: 2023/02/20 13:56:15 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(t_sl *sl, int dx, int dy)
{
	if ((sl->map.full_map[sl->pj.y_pj + dy][sl->pj.x_pj + dx] != '1'))
	{
		sl->map.full_map[sl->pj.y_pj][sl->pj.x_pj] = '0';
		sl->map.full_map[sl->pj.y_pj + dy][sl->pj.x_pj + dx] = 'P';
		sl->pj.x_pj += dx;
		sl->pj.y_pj += dy;
		img_to_map(&(sl->img), &(sl->vars), &(sl->map));
	}
}

int	ft_input(int keycode, t_sl *sl)
{
	if (keycode == 53)
		exit(1);
	printf("%c\n", sl->map.full_map[sl->pj.y_pj][sl->pj.x_pj - 1]);

	if (keycode == 0 || keycode == 123) //&& !(sl->map.full_map[sl->pj.y_pj][sl->pj.x_pj - 1] != 1))
		ft_move(sl, -1, 0);
	if (keycode == 2 || keycode == 124)
		ft_move(sl, 1, 0);
	if (keycode == 13  || keycode == 126)
		ft_move(sl, 0, -1);
	if (keycode == 1 || keycode == 125)
		ft_move(sl, 0, 1);
	return(0);
}
