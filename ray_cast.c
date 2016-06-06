/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 21:43:03 by rle-mino          #+#    #+#             */
/*   Updated: 2016/05/20 21:43:30 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wtd.h"

void	ray_cast(t_wolf *wolf)
{
	if (wolf->distwallx < wolf->distwally)
	{
		wolf->distwallx += wolf->dist2wallx;
		wolf->mapx += wolf->stepx;
		wolf->wallxory = 0;
	}
	else
	{
		wolf->distwally += wolf->dist2wally;
		wolf->mapy += wolf->stepy;
		wolf->wallxory = 1;
	}
}
