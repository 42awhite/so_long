/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:36:06 by ablanco-          #+#    #+#             */
/*   Updated: 2023/02/27 19:37:27 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_imgs(t_img *img, t_vars *vars)
{
	int		img_width;
	int		img_height;
	void	**xpm;

	xpm = &img->player;
	img->player = mlx_xpm_file_to_image(vars->mlx, DINO, 
	&img_width, &img_height);
	img->pj_r = mlx_xpm_file_to_image(vars->mlx, PR, &img_width, &img_height);
	img->pj_l = mlx_xpm_file_to_image(vars->mlx, "imag/Dino_izq1.xpm", &img_width, &img_height);
	img->pj_d = mlx_xpm_file_to_image(vars->mlx, "imag/Dino_down.xpm", &img_width, &img_height);
	img->pj_up = mlx_xpm_file_to_image(vars->mlx, "imag/Dino_up1.xpm", &img_width, &img_height);
	img->floor = mlx_xpm_file_to_image(vars->mlx, FLOOR, &img_width, &img_height);
	img->wall = mlx_xpm_file_to_image(vars->mlx, TREE, &img_width, &img_height);
	img->exit = mlx_xpm_file_to_image(vars->mlx, EGG, &img_width, &img_height);
	img->h[0] = mlx_xpm_file_to_image(vars->mlx, EGG, &img_width, &img_height);
	img->h[1] = mlx_xpm_file_to_image(vars->mlx, "imag/h2.xpm", &img_width, &img_height);
	img->h[2] = mlx_xpm_file_to_image(vars->mlx, "imag/h3.xpm", &img_width, &img_height);
	img->h[3] = mlx_xpm_file_to_image(vars->mlx, "imag/h4.xpm", &img_width, &img_height);
	img->h[4] = mlx_xpm_file_to_image(vars->mlx, "imag/h5.xpm", &img_width, &img_height);
	img->h[5] = mlx_xpm_file_to_image(vars->mlx, "imag/h6.xpm", &img_width, &img_height);
	img->h[6] = mlx_xpm_file_to_image(vars->mlx, "imag/h7.xpm", &img_width, &img_height);
	img->food = mlx_xpm_file_to_image(vars->mlx, FOOD, &img_width, &img_height);
	while (xpm[0] < img->food)
	{
		if (xpm[0] == NULL)
			ft_print_error("ERROR 404");
		xpm++;
	}
	if	(img->food == NULL)
		ft_print_error("PIZZA 404");
}

void	img_letter(char c, int x, int y, t_sl *sl)
{
	mlx_put_image_to_window(sl->vars.mlx, sl->vars.win, sl->img.floor, x * 60, y * 60);
	if (c == 'P')
		mlx_put_image_to_window(sl->vars.mlx, sl->vars.win, sl->img.player, x * 60, y * 60);
	else if (c  == '1')
		mlx_put_image_to_window(sl->vars.mlx, sl->vars.win, sl->img.wall, x * 60, y * 60);
	else if (c  == 'C')
		mlx_put_image_to_window(sl->vars.mlx, sl->vars.win, sl->img.food, x * 60, y * 60);
	if (x == sl->obj.x_ex && y == sl->obj.y_ex)
		mlx_put_image_to_window(sl->vars.mlx, sl->vars.win, sl->img.exit, x * 60, y * 60);
}

void	img_to_map (t_sl *sl)
{
	int		cont_x;
	int		cont_y;

	cont_x = 0;
	cont_y = 0;
	while (sl->map.full_map[cont_y])
	{
		while (sl->map.full_map[cont_y][cont_x] != '\n')
		{
			img_letter(sl->map.full_map[cont_y][cont_x], cont_x, cont_y, sl);
			cont_x++;
		}
		cont_x = 0;
		cont_y++;
	}
}

void	ft_win(t_sl *sl)
{
	static int	cont = 0;

	if (sl->obj.col == 0)
	{
		if(cont < 7)
		{
			mlx_put_image_to_window(sl->vars.mlx, sl->vars.win, sl->img.floor,
			 sl->obj.x_ex * 60, sl->obj.y_ex * 60);
			mlx_put_image_to_window(sl->vars.mlx, sl->vars.win, sl->img.h[cont],
			 sl->obj.x_ex * 60, sl->obj.y_ex * 60);
			cont++;
		}
		sl->img.exit = sl->img.h[6];
	}
}