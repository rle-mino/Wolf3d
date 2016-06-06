/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 12:01:31 by rle-mino          #+#    #+#             */
/*   Updated: 2016/05/25 16:18:43 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wtd.h"

void			cursor_move(t_mlx *mlx, int dir, double diff)
{
	double		old_dir_x;
	double		old_plane_x;
	t_wolf		*wolf;
	double		rad;

	wolf = mlx->wolf;
	rad = diff / mlx->wolf->sens;
	old_plane_x = wolf->planex;
	old_dir_x = wolf->dirx;
	if (dir == RIGHT)
	{
		wolf->dirx = wolf->dirx * cos(-rad) - wolf->diry * sin(-rad);
		wolf->diry = old_dir_x * sin(-rad) + wolf->diry * cos(-rad);
		wolf->planex = wolf->planex * cos(-rad) - wolf->planey * sin(-rad);
		wolf->planey = old_plane_x * sin(-rad) + wolf->planey * cos(-rad);
	}
	else
	{
		wolf->dirx = wolf->dirx * cos(rad) - wolf->diry * sin(rad);
		wolf->diry = old_dir_x * sin(rad) + wolf->diry * cos(rad);
		wolf->planex = wolf->planex * cos(rad) - wolf->planey * sin(rad);
		wolf->planey = old_plane_x * sin(rad) + wolf->planey * cos(rad);
	}
	mlx->m_left = 0;
	mlx->m_right = 0;
}

int				mouse_hook(int x, int y, t_mlx *mlx)
{
	static int		old_x = -1;

	(void)y;
	if (x > old_x)
	{
		mlx->m_left = 1;
		mlx->delta = old_x == -1 ? 1 : x - old_x;
	}
	else
	{
		mlx->m_right = 1;
		mlx->delta = old_x == -1 ? -1 : old_x - x;
	}
	old_x = x;
	return (1);
}

int				mouse_key_hook(int keycode, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (keycode == 4 && mlx->wolf->sens - 20 > 0)
		mlx->wolf->sens -= 20;
	if (keycode == 5 && mlx->wolf->sens + 20 < 1000)
		mlx->wolf->sens += 20;
	return (1);
}
