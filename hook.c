/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 13:26:59 by rle-mino          #+#    #+#             */
/*   Updated: 2016/05/26 21:20:06 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wtd.h"

void			start_hook(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1, enable_key, mlx);
	mlx_hook(mlx->win, 3, 2, disable_key, mlx);
	mlx_hook(mlx->win, 4, 0, mouse_key_hook, mlx);
	mlx_hook(mlx->win, 6, 0, mouse_hook, mlx);
	mlx_hook(mlx->win, 17, 0, red_cross_hook, mlx);
}

int				red_cross_hook(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

int				enable_key(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 13)
		mlx->up = 1;
	if (keycode == 1)
		mlx->down = 1;
	if (keycode == 0)
		mlx->left = 1;
	if (keycode == 2)
		mlx->right = 1;
	if (keycode == 123)
		mlx->ori_left = 1;
	if (keycode == 124)
		mlx->ori_right = 1;
	return (1);
}

int				disable_key(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
		mlx->up = 0;
	if (keycode == 1)
		mlx->down = 0;
	if (keycode == 0)
		mlx->left = 0;
	if (keycode == 2)
		mlx->right = 0;
	if (keycode == 123)
		mlx->ori_left = 0;
	if (keycode == 124)
		mlx->ori_right = 0;
	return (1);
}

int				get_loop(t_mlx *mlx)
{
	t_wolf		*wolf;
	int			b;

	wolf = mlx->wolf;
	b = 0;
	if (mlx->up == 1 && (b = 1))
		forward_and_backward(wolf, FORWARD);
	if (mlx->down == 1 && (b = 1))
		forward_and_backward(wolf, BACKWARD);
	if (mlx->left == 1 && (b = 1))
		left_and_right(wolf, LEFT);
	if (mlx->right == 1 && (b = 1))
		left_and_right(wolf, RIGHT);
	if (mlx->ori_left && (b = 1))
		cursor_move(mlx, LEFT, 15);
	if (mlx->ori_right && (b = 1))
		cursor_move(mlx, RIGHT, 15);
	if (mlx->m_left && (b = 1))
		cursor_move(mlx, RIGHT, mlx->delta);
	else if (mlx->m_right && (b = 1))
		cursor_move(mlx, LEFT, mlx->delta);
	if (b)
		redraw_wolf(mlx);
	return (0);
}
