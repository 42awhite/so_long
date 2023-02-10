/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:13:30 by ablanco-          #+#    #+#             */
/*   Updated: 2023/02/10 20:19:37 by ablanco-         ###   ########.fr       */
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
# include <mlx.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

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
}	t_objects;

typedef struct s_pj
{
	int		x_pj;
	int		y_pj;
}	t_pj;

typedef struct s_img
{
	void	*floor;
	void	*player;
	void	*wall;
	void	*exit;
	void	*food;
}	t_img;

typedef struct s_map
{
	t_sizem size;
	t_objects obj;
	t_pj    pj_start;
	char    **full_map;
	char    **p_map;
} t_map;


size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t cont, size_t size);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
void	ft_print_error(char *str);
void	ft_putstr(char *s);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif