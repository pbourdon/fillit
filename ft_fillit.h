/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishafie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:25:05 by ishafie           #+#    #+#             */
/*   Updated: 2016/01/12 22:49:22 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# define BUFFER 10
# define MAX 545
# include <string.h>

typedef struct	s_tetri
{
	int			l;
	int			nb_t;
	int			available;
	int			tc[4];
	char		letter;
	int			extend;
	int			nb_un;
	int			index;
}				t_tetri;

int				ft_strlen(const char *str);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, int n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
int				ft_sqrt(int n);
int				ft_isalpha(int c);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
void			*ft_memcpy(void *dst, const	void *src, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_atoa(char *str);
void			ft_putstr(char const *s);
void			ft_putnbr(int n);
void			ft_putchar(char c);
char			*ft_gt(char *av, int *len, int *nb_t);
int				ft_check_tetri(char *s, int index, int *nt);
t_tetri			*ft_conversion_tetriminos(char *s, const char *map,
											t_tetri *t_t);
char			*ft_create_map(char *s);
t_tetri			*ft_change_order(int *order, t_tetri *t_t);
int				*ft_plus_one(int *tab, int nb_t);
int				ft_check_nb_t(int *tab, int nb_t);
int				ft_check_double(int *tab, int nb_t);
int				ft_check_zero(int *tab, int nb_t);
int				ft_change(int *tab, int nb_t);
void			ft_display(char *s);
char			*create_map(int *len, t_tetri *t_t);
char			*modify_map(char *map);
char			*extend_map(char *map, t_tetri *t_t);
char			*ft_reset_map(char *map);
int				ft_add_to_map(char *map, t_tetri *t_t, int index,
								t_tetri *save);
int				ft_check_free(char *map, t_tetri *t_t, int index, int nt);
void			ft_ok_to_add(char *map, t_tetri *t_t, int index, int nt);
int				ft_compt(char *map);
int				ft_backtracking(char *map, t_tetri *t_t, int index, int nt);
int				ft_minimap(t_tetri *t_t, char *map, int nb_t);
int				ft_check_f(char *s, int i);
#endif
