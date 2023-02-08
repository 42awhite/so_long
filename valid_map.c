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
	int		cmp;

	size = ft_strlen(path_map) - 4;
	printf("\n%zu\n", size);
	cmp = ft_strncmp(".ber", &path_map[size], 4);
	printf("\n%d\n", cmp);
	if (cmp != 0)
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

int	ft_close(int keycode, t_vars *vars)
{
	(void)vars;
//	printf("%d\n", keycode);
	if (keycode == 53)
		exit(1);
	if (keycode == 0 || keycode == 123)
		printf("izqui\n");
	if (keycode == 2 || keycode == 124)
		printf("dere\n");
	if (keycode == 13  || keycode == 126)
		printf("arriba\n");
	if (keycode == 1 || keycode == 125)
		printf("abajo\n");
	return(0);
}



int main(int argc, char **argv)
{
	// la ruta tienes que obtener por parametros obtenidos en el main.
	t_map	map;

	if (argc == 1)
		return (1);
	ft_check_all_map(&map, argv[1]);
	void	*img;
	char	*relative_path = "/Users/ablanco-/Proyectos/solong/Dino1.xpm";
	//Anchura
	int		img_width;
	//altura
	int		img_height;
	t_vars	vars;

	vars.mlx = mlx_init();
	//Hacer función que te mida el ancho y el largo de la ventana
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	mlx_loop(vars.mlx);
}