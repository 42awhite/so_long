/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:22:14 by ablanco-          #+#    #+#             */
/*   Updated: 2023/03/01 16:34:59 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (full_map);
	close(fd);
}
