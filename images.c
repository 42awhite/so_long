/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:56:44 by ablanco-          #+#    #+#             */
/*   Updated: 2023/02/06 19:50:35 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "/Users/ablanco-/Proyectos/solong/Dino1.xpm";
	int		img_width;
	int		img_height;
    void	*mlx_win;
	int 	cont;
	int		dino_site;

	mlx = mlx_init();
								//  width, height
    mlx_win = mlx_new_window(mlx, 600, 600, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	cont = 0;
	dino_site = 0;
	while (cont < 10)
	{
												// x, y
    	mlx_put_image_to_window(mlx, mlx_win, img, dino_site, 0);
		cont++;
		dino_site = dino_site + 60;
	}
    printf("%p\n", img);
    mlx_loop(mlx);
}
