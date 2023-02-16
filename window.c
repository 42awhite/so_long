/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:56:44 by ablanco-          #+#    #+#             */
/*   Updated: 2023/02/16 17:29:34 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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


