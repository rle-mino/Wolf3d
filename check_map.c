/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:24:29 by rle-mino          #+#    #+#             */
/*   Updated: 2016/05/25 22:26:58 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wtd.h"

int			invalid_top_or_bot(int *line, int x_max)
{
	int		i;

	i = -1;
	while (++i < x_max)
		if (line[i] == 0)
			return (1);
	return (0);
}

int			invalid_left_or_right(t_wolf *wolf, int side)
{
	int		i;
	int		j;

	i = -1;
	j = side == LEFT ? 0 : wolf->size_map_x - 1;
	while (wolf->map[++i])
		if (wolf->map[i][j] == 0)
			return (1);
	return (0);
}

int			check_map(t_wolf *wolf)
{
	if (invalid_top_or_bot(wolf->map[0], wolf->size_map_x))
		return (-1);
	if (invalid_left_or_right(wolf, LEFT))
		return (-1);
	if (invalid_left_or_right(wolf, RIGHT))
		return (-1);
	if (invalid_top_or_bot(wolf->map[wolf->map_line - 1], wolf->size_map_x))
		return (-1);
	return (1);
}
