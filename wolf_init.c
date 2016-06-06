/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 21:35:17 by rle-mino          #+#    #+#             */
/*   Updated: 2016/06/06 11:32:32 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wtd.h"

void		get_spawn(t_wolf *wolf)
{
	int		i;
	int		j;

	i = -1;
	while (wolf->map[++i])
	{
		j = -1;
		while (++j < wolf->size_map_x)
		{
			if (wolf->map[i][j] == 0)
			{
				wolf->posx = i + 0.5;
				wolf->posy = j + 0.5;
				return ;
			}
		}
	}
	wtd_error(NO_SPAWN, NULL);
}

void		set_wolf(t_wolf *wolf, int x)
{
	wolf->camerax = 2 * x / (double)(SCSIZE) - 1;
	wolf->rayposx = wolf->posx;
	wolf->rayposy = wolf->posy;
	wolf->raydirx = wolf->dirx + wolf->planex * wolf->camerax;
	wolf->raydiry = wolf->diry + wolf->planey * wolf->camerax;
	wolf->distwallx = 0;
	wolf->distwally = 0;
	wolf->touch = 0;
	wolf->mapx = (int)(wolf->rayposx);
	wolf->mapy = (int)(wolf->rayposy);
	wolf->dist2wallx = sqrt(1 + (wolf->raydiry * wolf->raydiry) /
									(wolf->raydirx * wolf->raydirx));
	wolf->dist2wally = sqrt(1 + (wolf->raydirx * wolf->raydirx) /
									(wolf->raydiry * wolf->raydiry));
}

t_mlx		*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = ft_memalloc(sizeof(t_mlx));
	if (!(mlx->mlx = mlx_init()))
		return (NULL);
	mlx->win = mlx_new_window(mlx->mlx, SCSIZE, SCSIZE, "Wolf3D");
	mlx->img = mlx_new_image(mlx->mlx, SCSIZE, SCSIZE);
	mlx->img_data = mlx_get_data_addr(mlx->img, &(mlx->nbit),
												&(mlx->line), &(mlx->endian));
	return (mlx);
}

t_wolf		*init_wolf(void)
{
	t_wolf	*wolf;

	wolf = ft_memalloc(sizeof(t_wolf));
	wolf->dirx = -1;
	wolf->sens = 250;
	wolf->planey = 0.66;
	return (wolf);
}
