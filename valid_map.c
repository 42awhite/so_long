/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map->c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:49:26 by ablanco-          #+#    #+#             */
/*   Updated: 2023/02/07 19:13:30 by ablanco-         ###   ########.fr       */
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

void	ft_check_obj(char **map, t_objects *obj, t_pj *pos_pj)
{
	int	cont_x;
	int	cont_y;

	cont_x = 0;
	cont_y = 0;
	while (map[cont_y])
	{
		while(map[cont_y][cont_x] != '\n')
		{
			if (map[cont_y][cont_x] == 'C')
				obj->col++;
			else if (map[cont_y][cont_x] == 'P')
			{
				obj->pj++;
				pos_pj->x_pj = cont_x;
				pos_pj->y_pj = cont_y;
			}
			else if (map[cont_y][cont_x] == 'E')
				obj->exit++;
			cont_x++;
		}
		cont_y++;
		cont_x = 0;
	}
	if (obj->pj != 1 || obj->exit != 1)
		ft_print_error("n de obj o pj mal");
	if (obj->col < 1)
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
		while(p_map[y][x] != '\n')
		{
			if (p_map[y][x] == 'C' || p_map[y][x] == 'E')
				ft_print_error("Mapa no valido");
			x++;
		}
		y++;
		x = 0;
	}
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
	ft_check_obj(sl->map.full_map, &sl->obj, &sl->pj);
	ft_p_map(sl->map.p_map, sl->pj.x_pj, sl->pj.y_pj);
	ft_valid_map(sl->map.p_map);
}