/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:13:30 by ablanco-          #+#    #+#             */
/*   Updated: 2023/02/21 19:17:07 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include "libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

#define	 EGG	"imag/Egg1.xpm"
#define	 DINO 	"imag/Dino1.xpm"
#define  TREE 	"imag/tree.xpm"
#define	 FLOOR 	"imag/floor.xpm"
#define	 FOOD	"imag/pizza.xpm"


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_sizem
{
	//cambia por size_t
	int		x;
	int		y;
	int		x_win;
	int		y_win;
}	t_sizem;

typedef struct s_objects
{
	int		pj;
	int		exit;
	int     col;
	int		x_ex;
	int		y_ex;
}	t_objects;

typedef struct s_pj
{
	int		x_pj;
	int		y_pj;
}	t_pj;

typedef struct s_img
{
	void	*player;
	void	*pj_r;
	void	*pj_l;
	void	*pj_up;
	void	*pj_d;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*food;
}	t_img;

typedef struct s_map
{
	t_sizem size;
	char    **full_map;
	char    **p_map;
} t_map;

typedef struct s_sl
{
	t_map		map;
	t_objects 	obj;
	t_pj    	pj;
	t_vars		vars;
	t_img		img;
}t_sl;

char	*get_next_line(int fd);
void	ft_print_error(char *str);
void	ft_check_all_map(t_sl *sl, char *path_map);
void	sizexy_win(t_map *map);
void	img_to_map(t_img *img, t_vars *vars, t_map *map);
void	load_imgs(t_img *img, t_vars *vars);
int		ft_close(void);
void	ft_count_lines(char *path_map, t_sizem *size_map);
char	**ft_all_map(char *path_map, int n_lines);
void	ft_name_map(char *path_map);
int		ft_close(void);
void	sizexy_win(t_map *map);
void	load_imgs(t_img *img, t_vars *vars);
void	img_letter(char c, int x, int y, t_vars *vars, t_img *img);
void	img_to_map(t_img *img, t_vars *vars, t_map *map);
void	ft_move(t_sl *sl, int dx, int dy);
int		ft_input(int keycode, t_sl *sl);


#endif