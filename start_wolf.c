/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_wolf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 21:18:54 by rle-mino          #+#    #+#             */
/*   Updated: 2016/05/26 22:04:10 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wtd.h"

void	select_map_menu(t_wolf *wolf, t_mlx *mlx)
{
	(void)wolf;
	display_xpm("img/map1.xpm", mlx, 0);
	display_xpm("img/map2bw.xpm", mlx, 341);
	display_xpm("img/map3bw.xpm", mlx, 341 * 2);
	mlx->selected_map = 1;
	mlx->wolf = wolf;
	mlx_hook(mlx->win, 2, 0, select_hook, mlx);
	mlx_hook(mlx->win, 17, 0, red_cross_hook, mlx);
	mlx_loop(mlx->mlx);
}

void	use_custom_map(char *av, t_wolf *wolf, t_mlx *mlx)
{
	int		fd;

	(void)mlx;
	if ((fd = open(av, O_RDONLY)) < 0)
		wtd_error(ERRNO_ERR, NULL);
	if (!(wolf->map = get_map(fd, av, wolf)))
		wtd_error(MAP, wolf);
	if (check_map(wolf) == -1)
		wtd_error(BORDER, wolf);
	mlx->wolf = wolf;
	get_spawn(wolf);
	draw_wolf(wolf, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	start_hook(mlx);
	mlx_loop_hook(mlx->mlx, get_loop, mlx);
	mlx_loop(mlx->mlx);
}
