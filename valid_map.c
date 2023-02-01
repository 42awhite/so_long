/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:49:26 by ablanco-          #+#    #+#             */
/*   Updated: 2023/02/01 20:15:58 by ablanco-         ###   ########.fr       */
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
void	ft_count_lines(int fd, t_cosas *size_map)
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
	// printf("%s\n", map);
	full_map[n_lines] = map;
	map = get_next_line(fd);
	n_lines++;
  }
  return(full_map);
}

int main(void)
{
	int   fd;
	int	n_lines;
	char	**full_map;
	int	cont;
	t_cosas size_map;

	memset(&size_map, 0, sizeof(t_cosas));
	fd = open ("maps/map01", O_RDONLY);
	// n_lines = ft_count_lines(fd, &size_map);
	ft_count_lines(fd, &size_map);
	close(fd);
	fd = open ("maps/map01", O_RDONLY);
	full_map = ft_all_map(fd, size_map.y);
	close(fd);
	if (full_map == NULL)
	return (0);
	cont = 0;
	// while (full_map[cont])
  	// {
	// 	printf("fullmap\t%s", full_map[cont]);
	// 	cont++;
  	// }
  //system("leaks -q a.out");
}
