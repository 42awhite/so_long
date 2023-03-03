/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:42:30 by ablanco-          #+#    #+#             */
/*   Updated: 2023/03/03 17:20:38 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_char(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr(long int nbr)
{
	int	cont;

	cont = 0;
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbr *= -1;
		cont++;
	}
	if (nbr > 9)
		cont += ft_putnbr(nbr / 10);
	cont++;
	ft_char((nbr % 10) + '0');
	return (cont);
}
