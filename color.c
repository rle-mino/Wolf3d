/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 00:58:45 by rle-mino          #+#    #+#             */
/*   Updated: 2016/05/26 22:22:35 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wtd.h"

int			get_color(int xory, double rayx, double rayy)
{
	if (xory && rayy > 0)
		return (0xFF0000);
	else if (xory && rayy < 0)
		return (0x00FF00);
	else if (!xory && rayx > 0)
		return (0x0000FF);
	else
		return (0x00FFFF);
}
