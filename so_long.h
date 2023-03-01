/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:13:30 by ablanco-          #+#    #+#             */
/*   Updated: 2023/03/01 21:32:44 by ablanco-         ###   ########.fr       */
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
//# include "printf/ft_printf.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

# define DINO 	"imag/Dino1.xpm"
# define PR		"imag/Dino1.xpm"
# define PL		"imag/Dino_izq1.xpm"
# define PD		"imag/Dino_down.xpm"
# define PUP	"imag/Dino_up1.xpm"
# define TREE 	"imag/tree.xpm"
# define FLO 	"imag/floor.xpm"
# define FOOD	"imag/pizza.xpm"
# define EGG	"imag/Egg1.xpm"
# define H1		"imag/h2.xpm"
# define H2		"imag/h3.xpm"
# define H3		"imag/h4.xpm"
# define H4		"imag/h5.xpm"
# define H5		"imag/h6.xpm"
# define H6		"imag/h7.xpm"

typedef struct s_vars {
	void	*mlx;
	void	*win;
}t_vars;

typedef struct s_sizem
{
	int		x;
	int		y;
	int		x_win;
	int		y_win;
}t_sizem;

typedef struct s_objects
{
	int		pj;
	int		exit;
	int		col;
	int		x_ex;
	int		y_ex;
}t_objects;

typedef struct s_pj
{
	int		x_pj;
	int		y_pj;
}t_pj;

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
	void	*h[7];
	void	*food;
}t_img;

typedef struct s_map
{
	t_sizem	size;
	char	**full_map;
	char	**p_map;
}t_map;

typedef struct s_sl
{
	t_map		map;
	t_objects	obj;
	t_pj		pj;
	t_vars		vars;
	t_img		img;
	int			c_tim;
}t_sl;

char	*get_next_line(int fd);
void	ft_print_error(char *str);
void	ft_check_all_map(t_sl *sl, char *path_map);
void	img_to_map(t_sl *sl);
void	load_imgs(t_img *img, t_vars *vars);
void	ft_count_lines(char *path_map, t_sizem *size_map);
char	**ft_all_map(char *path_map, int n_lines);
void	ft_name_map(char *path_map);
int		ft_close(void);
void	sizexy_win(t_map *map);
void	img_letter(char c, int x, int y, t_sl *sl);
void	ft_move(t_sl *sl, int dx, int dy);
int		ft_input(int keycode, t_sl *sl);
void	ft_win(t_sl *sl);
void	ft_img_error(void **xpm, t_img *img);
void	ft_border_map(char **map, int x, int y);
void	ft_check_obj(char **map, t_sl *sl);
void	ft_p_map(char **map, int x_pj, int y_pj);
void	ft_valid_map(char **p_map);
int		ft_putnbr(long int nbr);
void	ft_char(char c);

#endif
