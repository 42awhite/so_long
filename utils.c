/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:09:52 by ablanco-          #+#    #+#             */
/*   Updated: 2023/02/16 15:46:15 by ablanco-         ###   ########.fr       */
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

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			q;
	unsigned char	*str;

	str = b;
	q = 0;
	while (q < len)
	{
		str[q] = (unsigned char) c;
		q++;
	}
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			c;
	unsigned char	*strs1;
	unsigned char	*strs2;

	strs1 = (unsigned char *)s1;
	strs2 = (unsigned char *)s2;
	c = 0;
	while ((strs1[c] != '\0' || strs2[c] != '\0') && c < n)
	{
		if (strs1[c] != strs2[c])
			return (strs1[c] - strs2[c]);
		c++;
	}
	return (0);
}