/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validator.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-boc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 20:11:53 by dvan-boc      #+#    #+#                 */
/*   Updated: 2019/05/21 20:11:57 by dvan-boc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

/*
** Checks if the tetrimino's are valid and
** if each Tetrimino Block touches atleast another block.
** Check if the read '#' tetrimino block has any adjacent blocks,
** if not, we can discard the tetrimino.
** @return 0 = Valid tetrimino set, -1 is invalid tetrimino set
** @param buf represents the string containing the tetrimino sample set.
*/

int			ft_validator(char *buf, int blocks, int adjacent, int dots)
{
	int index;
	int size;

	size = ft_strlen(buf) - 1;
	index = 0;
	while (index < size)
	{
		if ((buf[index] != '#' && buf[index] != '.' && buf[index] != '\n'))
			return (-1);
		if (buf[index] == '#')
		{
			blocks++;
			check_adjacent(&buf, &index, &adjacent);
		}
		buf[index] != '.' || dots++;
		index++;
	}
	if (adjacent < 6 || blocks != 4 || dots != 12)
		return (-1);
	return (0);
}

void		check_adjacent(char **buf, int *index, int *adjacent)
{
	char	*grid;
	int		size;

	grid = *buf;
	size = ft_strlen(grid);
	if (*index - 1 >= 0 && grid[*index - 1] == '#')
		*adjacent += 1;
	if (*index + 1 <= size && grid[*index + 1] == '#')
		*adjacent += 1;
	if (*index + 5 <= size && grid[*index + 5] == '#')
		*adjacent += 1;
	if (*index - 5 >= 0 && grid[*index - 5] == '#')
		*adjacent += 1;
}
