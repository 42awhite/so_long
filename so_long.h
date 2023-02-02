/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:13:30 by ablanco-          #+#    #+#             */
/*   Updated: 2023/02/02 13:30:37 by ablanco-         ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

typedef struct s_sizem
{
    int		x;
    int		y;
}	t_sizem;

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t cont, size_t size);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
void	ft_print_error(char *str);
void	ft_putstr(char *s);

#endif