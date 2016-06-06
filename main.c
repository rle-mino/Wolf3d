/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:06:28 by rle-mino          #+#    #+#             */
/*   Updated: 2016/05/26 22:03:57 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wtd.h"

int		main(int ac, char **av)
{
	t_wolf	*wolf;
	t_mlx	*mlx;

	wolf = init_wolf();
	mlx = NULL;
	if (!(mlx = init_mlx()))
		wtd_error(INIT, wolf);
	if (ac == 1)
		select_map_menu(wolf, mlx);
	else
		use_custom_map(av[1], wolf, mlx);
}
