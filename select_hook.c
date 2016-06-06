/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:22:49 by rle-mino          #+#    #+#             */
/*   Updated: 2016/05/26 22:17:04 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wtd.h"

static int			**select_map(int id_map, t_wolf *wolf)
{
	char	*path;
	char	*tmp;
	int		**map;
	int		fd;

	tmp = ft_itoa(id_map);
	path = ft_strjoin("maps/map", tmp);
	fd = open(path, O_RDONLY);
	free(tmp);
	if (!(map = get_map(fd, path, wolf)))
		wtd_error(MAP, wolf);
	free(path);
	return (map);
}

void				display_xpm(char *path, t_mlx *mlx, int start)
{
	int		width;
	int		height;

	mlx->xpm_img = mlx_xpm_file_to_image(mlx->mlx, path,
												&width, &height);
	if (!mlx->xpm_img)
		wtd_error(IMG_DEL, NULL);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->xpm_img, 0, start);
	mlx_destroy_image(mlx->mlx, mlx->xpm_img);
}

static void			low_key(t_mlx *mlx)
{
	if (mlx->selected_map == 1)
	{
		display_xpm("img/map1bw.xpm", mlx, 0);
		display_xpm("img/map2.xpm", mlx, 341);
		display_xpm("img/map3bw.xpm", mlx, 341 * 2);
	}
	else if (mlx->selected_map == 2)
	{
		display_xpm("img/map1bw.xpm", mlx, 0);
		display_xpm("img/map2bw.xpm", mlx, 341);
		display_xpm("img/map3.xpm", mlx, 341 * 2);
	}
	else if (mlx->selected_map == 3)
	{
		display_xpm("img/map1.xpm", mlx, 0);
		display_xpm("img/map2bw.xpm", mlx, 341);
		display_xpm("img/map3bw.xpm", mlx, 341 * 2);
	}
	mlx->selected_map++;
	if (mlx->selected_map > 3)
		mlx->selected_map = 1;
}

static void			up_key(t_mlx *mlx)
{
	if (mlx->selected_map == 1)
	{
		display_xpm("img/map1bw.xpm", mlx, 0);
		display_xpm("img/map2bw.xpm", mlx, 341);
		display_xpm("img/map3.xpm", mlx, 341 * 2);
	}
	else if (mlx->selected_map == 2)
	{
		display_xpm("img/map1.xpm", mlx, 0);
		display_xpm("img/map2bw.xpm", mlx, 341);
		display_xpm("img/map3bw.xpm", mlx, 341 * 2);
	}
	else if (mlx->selected_map == 3)
	{
		display_xpm("img/map1bw.xpm", mlx, 0);
		display_xpm("img/map2.xpm", mlx, 341);
		display_xpm("img/map3bw.xpm", mlx, 341 * 2);
	}
	mlx->selected_map--;
	if (mlx->selected_map < 1)
		mlx->selected_map = 3;
}

int					select_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 126)
		up_key(mlx);
	else if (keycode == 125)
		low_key(mlx);
	else if (keycode == 36)
	{
		mlx->wolf->map = select_map(mlx->selected_map, mlx->wolf);
		if (check_map(mlx->wolf) == -1)
			wtd_error(BORDER, mlx->wolf);
		get_spawn(mlx->wolf);
		draw_wolf(mlx->wolf, mlx);
		start_hook(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
		start_hook(mlx);
		mlx_loop_hook(mlx->mlx, get_loop, mlx);
	}
	else if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (1);
}
