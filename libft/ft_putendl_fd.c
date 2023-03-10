/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:23:08 by ablanco-          #+#    #+#             */
/*   Updated: 2022/09/29 18:09:09 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	cont;

	if (s != NULL)
	{
		cont = 0;
		while (s[cont])
		{
			write(fd, &s[cont], 1);
			cont++;
		}
		write(fd, "\n", 1);
	}
}
