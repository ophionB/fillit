/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-boc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 18:42:11 by dvan-boc      #+#    #+#                 */
/*   Updated: 2019/03/28 18:42:14 by dvan-boc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
** T_SIZE represents the maximum amount of tetrimino's
** BUFF_SIZE represents the maximum amount of bits read
*/
# define BUFF_SIZE 21

# include "../libft/includes/libft.h"

/*
** @struct Typedef = tetrimino
** X, represents the horizontal coordinate of the 4x4 block
** Y, represents the vertical coordinate of the 4x4 block
** ID, represents the tetrimino ID.
*/

typedef struct	s_sq
{
	int			x[4];
	int			y[4];
	char		letter;
	int			grid_y;
	int			grid_x;
	struct s_sq	*next;
}				t_tetrimino;

int				ft_read(const char *file, char **buf);
int				ft_validator(char *buf, int blocks, int adjacent, int dots);
void			ft_solve(t_tetrimino *lst, size_t size);
t_tetrimino		*ft_sort_list(char **buf, int x, int y, int block);
void			subtract_coordinates(t_tetrimino *head, int check, int lowest);
int				check_tetr(char **grid, t_tetrimino curr, int ind_y, int ind_x);
int				check_all_tetr(char **grid, t_tetrimino *curr);
char			**ft_grid_gen(size_t size);
size_t			ft_calc_sqrt(size_t size);
int				add_to_grid(char **grid, t_tetrimino current, int y, int x);
void			delete_from_grid(char **grid, t_tetrimino current);
void			reset_vars(int *block, int *x, int *y, int *index);
void			set_tetr_properties(t_tetrimino **curr);
void			check_adjacent(char **buf, int *index, int *adjacent);
void			set_coords(t_tetrimino **curr, int *block, int x, int y);
void			ft_next_pos(char pos, int *index, int *y, int *x);
void			ft_shutdown(t_tetrimino *lst);

#endif
