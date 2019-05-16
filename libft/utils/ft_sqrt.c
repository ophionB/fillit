/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sqrt.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-boc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 13:51:21 by dvan-boc      #+#    #+#                 */
/*   Updated: 2019/02/03 13:51:22 by dvan-boc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int    ft_sqrt(int nb)
{
	int    i;
	int    r;

	i = 1;
	r = 0;
	if (nb == 1 || nb == 0)
		return (nb);
	while (r < nb)
	{
		r = i * i;
		i++;
	}
	if (r == nb)
		return (i - 1);
	return (0);
}