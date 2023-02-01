/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:09:52 by ablanco-          #+#    #+#             */
/*   Updated: 2023/02/01 20:17:37 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "so_long.h"

void	ft_putstr(char *s)
{
	int		cont;

	if (s != '\0')
	{
		cont = 0;
		while (s[cont])
		{
			write(1, &s[cont], 1);
			cont++;
		}
	}
}

void	ft_print_error(char *str)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	ft_putstr("\n");
	exit(0);
}