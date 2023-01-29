/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:49:26 by ablanco-          #+#    #+#             */
/*   Updated: 2023/01/29 16:49:29 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

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

int main(void)
{
  t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};
	char**  area = ft_make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");
}