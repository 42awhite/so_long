/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:36:06 by ablanco-          #+#    #+#             */
/*   Updated: 2023/02/21 19:58:00 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_imgs(t_img *img, t_vars *vars)
{
	int		img_width;
	int		img_height;
	img->player = mlx_xpm_file_to_image(vars->mlx, "imag/Dino1.xpm", &img_width, &img_height);
	img->pj_r = mlx_xpm_file_to_image(vars->mlx, "imag/Dino1.xpm", &img_width, &img_height);
	img->pj_l = mlx_xpm_file_to_image(vars->mlx, "imag/Dino_izq1.xpm", &img_width, &img_height);
	img->pj_d = mlx_xpm_file_to_image(vars->mlx, "imag/Dino_down.xpm", &img_width, &img_height);
	img->pj_up = mlx_xpm_file_to_image(vars->mlx, "imag/Dino_up1.xpm", &img_width, &img_height);
	img->floor = mlx_xpm_file_to_image(vars->mlx, FLOOR, &img_width, &img_height);
	img->wall = mlx_xpm_file_to_image(vars->mlx, TREE, &img_width, &img_height);
	img->exit = mlx_xpm_file_to_image(vars->mlx, EGG, &img_width, &img_height);
	img->food = mlx_xpm_file_to_image(vars->mlx, FOOD, &img_width, &img_height);
}

void	img_letter(char c, int x, int y, t_vars *vars, t_img *img)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img->floor, x * 60, y * 60);
	if (c == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, img->player, x * 60, y * 60);
	else if (c  == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, img->wall, x * 60, y * 60);
	else if (c  == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, img->food, x * 60, y * 60);
	else if (c  == 'E') // if aparte x == img->obj->x_ex  && y == img->obj->y_ex;
		mlx_put_image_to_window(vars->mlx, vars->win, img->exit, x * 60, y * 60);
}

void	img_to_map(t_img *img, t_vars *vars, t_map *map)
{
	int		cont_x;
	int		cont_y;

	cont_x = 0;
	cont_y = 0;
	while (map->full_map[cont_y])
	{
		while (map->full_map[cont_y][cont_x] != '\n')
		{
			img_letter(map->full_map[cont_y][cont_x], cont_x, cont_y, vars, img);
			cont_x++;
		}
		cont_x = 0;
		cont_y++;
	}
}