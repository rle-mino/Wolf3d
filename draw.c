/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 21:45:59 by rle-mino          #+#    #+#             */
/*   Updated: 2016/06/01 14:51:48 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wtd.h"

int				redraw_wolf(t_mlx *mlx)
{
	t_wolf		*wolf;

	wolf = mlx->wolf;
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, SCSIZE, SCSIZE);
	mlx->img_data = mlx_get_data_addr(mlx->img, &mlx->nbit, &mlx->line,
																&mlx->endian);
	draw_wolf(wolf, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

static void		put_pixel_to_image(t_mlx *mlx, int x, int y, int color)
{
	int		i;

	i = x * (mlx->nbit >> 3) + (y * mlx->line);
	mlx->img_data[i] = (color >> 16) % 256;
	mlx->img_data[i + 1] = (color >> 8) % 256;
	mlx->img_data[i + 2] = color % 256;
}

static void		ft_draw(t_mlx *mlx, int x, t_wolf *wolf)
{
	int		i;
	int		color;

	i = 0;
	color = get_color(wolf->wallxory, wolf->raydirx, wolf->raydiry);
	while (i < wolf->drawstart)
	{
		put_pixel_to_image(mlx, x, i, 0xFFFF00);
		i++;
	}
	while (wolf->drawstart < wolf->drawend)
	{
		put_pixel_to_image(mlx, x, wolf->drawstart, color);
		wolf->drawstart++;
	}
	while (wolf->drawend < SCSIZE - 1)
	{
		put_pixel_to_image(mlx, x, wolf->drawend, 0xBEBEBE);
		wolf->drawend++;
	}
}

static void		draw_vertically(t_wolf *wolf, t_mlx *mlx, int x)
{
	wolf->drawstart = -(wolf->wall_height) / 2 + SCSIZE / 2;
	if (wolf->drawstart < 0)
		wolf->drawstart = 0;
	wolf->drawend = wolf->wall_height / 2 + SCSIZE / 2;
	if (wolf->drawend >= SCSIZE)
		wolf->drawend = SCSIZE - 1;
	ft_draw(mlx, x, wolf);
}

void			draw_wolf(t_wolf *wolf, t_mlx *mlx)
{
	int		x;

	x = -1;
	while (++x < SCSIZE)
	{
		set_wolf(wolf, x);
		get_dist_wall(wolf);
		while (wolf->touch == 0)
		{
			ray_cast(wolf);
			if (wolf->map[wolf->mapx][wolf->mapy] > 0)
				wolf->touch = 1;
		}
		get_wall_size(wolf);
		draw_vertically(wolf, mlx, x);
	}
}
