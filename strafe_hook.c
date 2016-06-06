/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strafe_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 21:57:51 by rle-mino          #+#    #+#             */
/*   Updated: 2016/05/24 00:39:51 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wtd.h"

double			ft_deg_to_rad(double degrees)
{
	double		pi;

	pi = 3.14159265;
	return (degrees * (pi / 100));
}

void			forward_and_backward(t_wolf *wolf, int dir)
{
	if (dir == FORWARD)
	{
		if (!(wolf->map[(int)(wolf->posx + wolf->dirx * 0.15)]
														[(int)wolf->posy]))
			wolf->posx += wolf->dirx * 0.15;
		if ((!wolf->map[(int)wolf->posx]
							[(int)(wolf->posy + wolf->diry * 0.15)]))
			wolf->posy += wolf->diry * 0.15;
	}
	else
	{
		if (!(wolf->map[(int)(wolf->posx - wolf->dirx * 0.15)]
															[(int)wolf->posy]))
			wolf->posx -= wolf->dirx * 0.15;
		if ((!wolf->map[(int)wolf->posx]
								[(int)(wolf->posy - wolf->diry * 0.15)]))
			wolf->posy -= wolf->diry * 0.15;
	}
}

void			left_and_right(t_wolf *wolf, int dir)
{
	if (dir == LEFT)
	{
		if (!(wolf->map[(int)(wolf->posx - wolf->planex * 0.15)]
															[(int)wolf->posy]))
			wolf->posx -= wolf->planex * 0.15;
		if ((!wolf->map[(int)wolf->posx]
								[(int)(wolf->posy - wolf->planey * 0.15)]))
			wolf->posy -= wolf->planey * 0.15;
	}
	else
	{
		if (!(wolf->map[(int)(wolf->posx + wolf->planex * 0.15)]
															[(int)wolf->posy]))
			wolf->posx += wolf->planex * 0.15;
		if ((!wolf->map[(int)wolf->posx]
								[(int)(wolf->posy + wolf->planey * 0.15)]))
			wolf->posy += wolf->planey * 0.15;
	}
}
