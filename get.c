/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 21:39:45 by rle-mino          #+#    #+#             */
/*   Updated: 2016/05/20 22:08:00 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wtd.h"

void		get_wall_size(t_wolf *wolf)
{
	if (wolf->wallxory == 0)
		wolf->wall_length = fabs((wolf->mapx - wolf->rayposx +
										(1 - wolf->stepx) / 2) / wolf->raydirx);
	else
		wolf->wall_length = fabs((wolf->mapy - wolf->rayposy +
										(1 - wolf->stepy) / 2) / wolf->raydiry);
	wolf->wall_height = abs((int)(SCSIZE / wolf->wall_length));
}

void		get_dist_wall(t_wolf *wolf)
{
	if (wolf->raydirx < 0)
	{
		wolf->stepx = -1;
		wolf->distwallx = (wolf->rayposx - wolf->mapx) * wolf->dist2wallx;
	}
	else
	{
		wolf->stepx = 1;
		wolf->distwallx = (wolf->mapx + 1.0 - wolf->rayposx) * wolf->dist2wallx;
	}
	if (wolf->raydiry < 0)
	{
		wolf->stepy = -1;
		wolf->distwally = (wolf->rayposy - wolf->mapy) * wolf->dist2wally;
	}
	else
	{
		wolf->stepy = 1;
		wolf->distwally = (wolf->mapy + 1.0 - wolf->rayposy) * wolf->dist2wally;
	}
}
