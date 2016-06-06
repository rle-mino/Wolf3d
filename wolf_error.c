/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 18:56:02 by rle-mino          #+#    #+#             */
/*   Updated: 2016/06/06 11:32:09 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wtd.h"

void		display_errors(t_wolf *wolf)
{
	int	i;
	int	j;

	i = -1;
	while (wolf->map[++i])
	{
		j = -1;
		while (++j < wolf->size_map_x)
		{
			if ((i == 0 && wolf->map[i][j] == 0) ||
					(j == wolf->size_map_x - 1 && wolf->map[i][j] == 0) ||
					(j == 0 && wolf->map[i][j] == 0) ||
					(!wolf->map[i + 1] && wolf->map[i][j] == 0))
				fpf("%s%-2d%s", C_RED, wolf->map[i][j], C_RES);
			else
				fpf("%-2d", wolf->map[i][j]);
		}
		fpf("\n");
	}
}

int			wtd_error(int err, t_wolf *wolf)
{
	if (err == INIT)
		ft_putstr_fd("mlx_init failed\n", 2);
	if (err == MAP)
	{
		ft_putstr_fd("Invalid, make sure the map is quadrilateral ", 2);
		ft_putstr_fd("and she contains positive numbers and spaces only\n", 2);
	}
	if (err == BORDER)
	{
		ft_putstr_fd("Invalid, make sure the map has borders\n", 2);
		display_errors(wolf);
	}
	if (err == SMALL)
		ft_putstr_fd("Invalid, map is too small. min size = 3x3\n", 2);
	if (err == IMG_DEL)
		ft_putstr_fd("Start menu unavailable\n", 2);
	if (err == ERRNO_ERR)
		perror("Wolf3d");
	if (err == NO_SPAWN)
		ft_putstr_fd("Impossible to find a spawn location\n", 2);
	exit(EXIT_FAILURE);
	return (0);
}
