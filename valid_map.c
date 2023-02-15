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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "so_long.h"

void	ft_name_map(char *path_map)
{
	size_t	size;

	size = ft_strlen(path_map) - 4;
	if (ft_strncmp(".ber", &path_map[size], 4) != 0)
		ft_print_error("el mapa no acaba en .ber");
}

void	ft_count_lines(char *path_map, t_sizem *size_map)
{
	
	char	*map;
	int		fd;

	fd = open (path_map, O_RDONLY);
	map = get_next_line(fd);
	size_map->x = ft_strlen(map);
	while (map != NULL)
	{
		free(map);
		size_map->y++;
		map = get_next_line(fd);
		//CUIDADO con el casteo
		if (map && size_map->x != (int)ft_strlen(map))
			ft_print_error("Lineas no iguales");
	}
		close(fd);
}

char	**ft_all_map(char *path_map, int n_lines)
{
	char	**full_map;
	char	*map;
	int		fd;

	fd = open (path_map, O_RDONLY);
	full_map = ft_calloc((n_lines + 1), sizeof(char *));
	if (!full_map)
		return (0);
	map = get_next_line(fd);
	n_lines = 0;
	while (map != NULL)
	{	
		full_map[n_lines] = map;
		map = get_next_line(fd);
		n_lines++;
	}
	return(full_map);
	close(fd);
}

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

void	ft_check_all_map(t_map *map, char *path_map)
{
	ft_name_map(path_map);
	ft_memset(map, 0, sizeof(t_map));
	ft_count_lines(path_map, &map->size);
	map->full_map = ft_all_map(path_map, map->size.y);
	if (map->full_map == NULL)
		return ;
	map->p_map = ft_all_map(path_map, map->size.y);
	if (map->p_map == NULL)
		return ;
	ft_border_map(map->full_map, map->size.x, map->size.y);
	ft_check_obj(map->full_map, &map->obj, &map->pj_start);
	ft_p_map(map->p_map, map->pj_start.x_pj, map->pj_start.y_pj);
	ft_valid_map(map->p_map);
}

//DE AQUI PARA ARRIBA ES PARA CHECKEAR MAPA
int	ft_close(void)
{
	exit(1);
	return(0);
}

void	sizexy_win(t_map *map)
{
	map->size.x_win = (map->size.x - 1) * 60;
	map->size.y_win = map->size.y * 60;
}

void	load_imgs(t_img *img, t_vars *vars)
{
	int		img_width;
	int		img_height;
	img->player = mlx_xpm_file_to_image(vars->mlx, DINO, &img_width, &img_height);
	img->floor = mlx_xpm_file_to_image(vars->mlx, FLOOR, &img_width, &img_height);
	img->wall = mlx_xpm_file_to_image(vars->mlx, TREE, &img_width, &img_height);
	img->exit = mlx_xpm_file_to_image(vars->mlx, EGG, &img_width, &img_height);
	img->food = mlx_xpm_file_to_image(vars->mlx, FOOD, &img_width, &img_height);
}

int	ft_input(int keycode, t_map *map)
{
	//	printf("%d\n", keycode);
	printf("X: [%d], Y: [%d]\n", map->pj_start.x_pj, map->pj_start.y_pj);
	printf("%p %p %p\n", map->vars.mlx, map->vars.win, map->img.floor);
	if (keycode == 53)
		exit(1);
	if (keycode == 0 || keycode == 123)
	{
		printf("izqui\n");
		ft_move(map, -1, 0);
	}
	if (keycode == 2 || keycode == 124)
		printf("dere\n");
	if (keycode == 13  || keycode == 126)
		printf("arriba\n");
	if (keycode == 1 || keycode == 125)
		printf("abajo\n");
	
	return(0);
}

void	img_letter(char c, int x, int y, t_vars *vars, t_img *img)
{
	printf("%p %p %p\n", vars->mlx, vars->win, img->floor);
	mlx_put_image_to_window(vars->mlx, vars->win, img->floor, x * 60, y * 60);
	if (c == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, img->player, x * 60, y * 60);
	else if (c  == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, img->wall, x * 60, y * 60);
	else if (c  == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, img->food, x * 60, y * 60);
	else if (c  == 'E')
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

void	ft_move(t_map *map, int x, int y)
{
	map->full_map[map->pj_start.y_pj][map->pj_start.x_pj] = '0';
	map->full_map[map->pj_start.y_pj + y][map->pj_start.x_pj + x] = 'P';
	map->pj_start.x_pj += x;
	map->pj_start.y_pj += y;
	printf("X: [%d], Y: [%d]\n", map->pj_start.x_pj, map->pj_start.y_pj);
	printf("%p %p %p\n", map->vars.mlx, map->vars.win, map->img.floor);
	img_to_map(&map->img, &map->vars, map);
}

int main(int argc, char **argv)
{
	// la ruta tienes que obtener por parametros obtenidos en el main.
	t_map	map;
	t_img	img;

	if (argc == 1)
		return (1);
	ft_check_all_map(&map, argv[1]);
	//ft_memset(&img, 0, sizeof(t_img));
	map.vars.mlx = mlx_init();
	sizexy_win(&map);
	map.vars.win = mlx_new_window(map.vars.mlx, map.size.x_win, map.size.y_win, "I'm a SEXY window!! :)");
	load_imgs(&img, &map.vars);
	img_to_map(&img, &map.vars, &map);
	printf("x:%d\n", map.pj_start.x_pj);
	printf("y:%d\n", map.pj_start.y_pj);
	printf("INICIO: %p %p %p\n", map.vars.mlx, map.vars.win, map.img.floor);
	mlx_key_hook(map.vars.win, ft_input, &map);
	mlx_hook(map.vars.win, 17, 0, ft_close, &map.vars);
	mlx_loop(map.vars.mlx);
}
