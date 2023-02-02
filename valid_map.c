/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:49:26 by ablanco-          #+#    #+#             */
/*   Updated: 2023/02/02 16:28:49 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "so_long.h"
/*
typ 
char**  ft_make_area(char ** zone, t_point size)
{
	char**  new;
	int     pos_y;
	int     pos_x;

	new = malloc(sizeof(char*) * size.y);
	pos_x = 0;
	while (pos_x <= size.y)
	{
		new[pos_x] = malloc(size.x + 1);
		pos_x++;
		pos_y = 0;
		while(pos_y <= size.x)
		{
			new[pos_y][pos_x] = zone[pos_y][pos_x];
		   // pos_x++;
			pos_y++;
		}
	  new[pos_y][size.x] = '\0';
	}
	return(new);
}
*/
void	ft_count_lines(int fd, t_sizem *size_map)
{
	char	*map;

	map = get_next_line(fd);
	size_map->x = ft_strlen(map);
	while (map != NULL)
	{
		free(map);
		size_map->y++;
		map = get_next_line(fd);
		if (map && size_map->x != ft_strlen(map))
			ft_print_error("Lineas no iguales");
	}
}

char	**ft_all_map(int fd, int n_lines)
{
char	**full_map;
char	*map;

printf("numero lineas:%d\n", n_lines);
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
}

void	ft_border_map(char **map, int x, int y)
{	
	int		cont;

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

int main(void)
{
	int		fd;
	int		n_lines;
	char	**full_map;
	int		cont;
	t_sizem	size_map;

	memset(&size_map, 0, sizeof(t_sizem));
	fd = open ("maps/map01", O_RDONLY);
	ft_count_lines(fd, &size_map);
	close(fd);
	fd = open ("maps/map01", O_RDONLY);
	full_map = ft_all_map(fd, size_map.y);
	close(fd);
	if (full_map == NULL)
		return (0);
	ft_border_map(full_map, size_map.x, size_map.y);
}
