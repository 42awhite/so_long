/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:37:56 by ablanco-          #+#    #+#             */
/*   Updated: 2023/03/01 18:16:42 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_border_map(char **map, int x, int y)
{	
	int	cont;

	cont = 0;
	while (cont < (x - 1))
	{
		if (map[0][cont] != '1' || map[(y - 1)][cont] != '1')
			ft_print_error("contorno x mal");
		cont++;
	}
	cont = 0;
	while (cont < y)
	{
		if (map[cont][0] != '1' || map[cont][(x - 2)] != '1')
			ft_print_error("contorno y mal");
		cont++;
	}
}

void	ft_n_obj(t_sl *sl, char c, int cont_y, int cont_x)
{
	if (c == 'C')
		sl->obj.col++;
	else if (c == 'P')
	{
		sl->obj.pj++;
		sl->pj.x_pj = cont_x;
		sl->pj.y_pj = cont_y;
	}
	else if (c == 'E')
	{
		sl->obj.exit++;
		sl->obj.x_ex = cont_x;
		sl->obj.y_ex = cont_y;
	}
}

void	ft_check_obj(char **map, t_sl *sl)
{
	int	cont_x;
	int	cont_y;

	cont_y = 0;
	cont_x = 0;
	while (map[cont_y])
	{
		while (map[cont_y][cont_x] != '\n')
		{
			ft_n_obj(sl, map[cont_y][cont_x], cont_y, cont_x);
			cont_x++;
		}
		cont_y++;
		cont_x = 0;
	}
	if (sl->obj.pj != 1 || sl->obj.exit != 1)
		ft_print_error("n de obj o pj mal");
	if (sl->obj.col < 1)
		ft_print_error("No hay coleccionables");
}

void	ft_p_map(char **map, int x_pj, int y_pj)
{
	if (map[y_pj][x_pj + 1] != '1' && map[y_pj][x_pj + 1] != 'P')
	{
		map[y_pj][x_pj + 1] = 'P';
		ft_p_map(map, x_pj + 1, y_pj);
	}
	if (map[y_pj][x_pj - 1] != '1' && map[y_pj][x_pj - 1] != 'P')
	{
		map[y_pj][x_pj - 1] = 'P';
		ft_p_map(map, x_pj - 1, y_pj);
	}
	if (map[y_pj + 1][x_pj] != '1' && map[y_pj + 1][x_pj] != 'P')
	{
		map[y_pj + 1][x_pj] = 'P';
		ft_p_map(map, x_pj, y_pj + 1);
	}
	if (map[y_pj - 1][x_pj] != '1' && map[y_pj - 1][x_pj] != 'P')
	{
		map[y_pj - 1][x_pj] = 'P';
		ft_p_map(map, x_pj, y_pj - 1);
	}
}

void	ft_valid_map(char **p_map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (p_map[y])
	{
		while (p_map[y][x] != '\n')
		{
			if (p_map[y][x] == 'C' || p_map[y][x] == 'E')
				ft_print_error("Mapa no valido");
			x++;
		}
		y++;
		x = 0;
	}
}	
