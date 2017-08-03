/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryukhyme <ryukhyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:55:22 by ryukhyme          #+#    #+#             */
/*   Updated: 2017/01/06 18:58:10 by ryukhyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 546
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

char			*g_coord[20];

typedef struct	s_coord
{
	int			c;
	int			r;
}				t_coord;

typedef	struct	s_td
{
	t_coord tet[4];
	char	letter;

}				t_td;

typedef	struct	s_board
{
	char		**brd;
	t_coord		*in_t;
	int			size;
	int			ntetri;
}				t_board;

void			*ft_memset(void *b, int c, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strnew(size_t size);
char			*ft_strcpy(char *dst, const char *src);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			**ft_strsplit(char const *s, char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				read_file(char *buffer, int argc, char **argv);
int				val_nl(char *str);
int				count_t(char *str);
int				ft_val_str(char *str);
char			***tetri_arr(char *str);
int				check_conect(char **arr);
int				connection(char ***aarr);
char			*trim_dnl(char const *s);
void			trim(char **arr);
int				*input_tets(char *str);
void			patern(void);
char			**tabjoin(char **tab);
void			sqr_valid(char *str);
char			*get_patern(int i);
char			*s2a(char *s, int i);
int				tetri_count(int *input);
t_coord			*create_vr_coords(void);
t_coord			rollback_s(t_board *wboard, t_td ct, int *i);
int				board_size(int size, int *input);
void			print_result(char ***pr_board, int size);
char			**create_pr_board(int size);
void			coord(void);
t_td			write_ctet(t_td tetri, int ntet, int let);
t_coord			find_pos(t_board wboard, t_coord in_pos);
t_td			*create_str(int *input);
void			insert(t_board wboard, t_coord av_pos, t_td ct, int *i);
void			slower(int *m_input);
int				is_reals(t_board wboard, t_coord av_pos, t_td ct, int *i);
int				solve_pros(t_board wboard, int *m_input);
#endif
