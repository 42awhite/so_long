/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:22:14 by ablanco-          #+#    #+#             */
/*   Updated: 2023/01/17 17:22:17 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	(void)vars;
	printf("%d\n", keycode);
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

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}