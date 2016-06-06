/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:41:22 by rle-mino          #+#    #+#             */
/*   Updated: 2016/06/06 11:27:30 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WTD_H
# define WTD_H

# include "libft.h"
# include "colors.h"
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# define SCSIZE 1024

enum
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

enum
{
	BORDER,
	INIT,
	MAP,
	SMALL,
	ERRNO_ERR,
	IMG_DEL,
	NO_SPAWN
};

typedef struct		s_wolf
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			distwallx;
	double			distwally;
	double			dist2wallx;
	double			dist2wally;
	double			wall_length;
	int				stepx;
	int				stepy;
	int				touch;
	int				wallxory;
	int				drawstart;
	int				drawend;
	int				wall_height;
	int				mapx;
	int				mapy;
	int				sens;
	int				**map;
	int				size_map_x;
	int				map_line;
}					t_wolf;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	t_wolf			*wolf;
	char			*img_data;
	void			*xpm_img;
	int				selected_map;
	int				nbit;
	int				line;
	int				endian;
	int				left;
	int				right;
	int				up;
	int				down;
	int				ori_left;
	int				ori_right;
	int				delta;
	int				m_left;
	int				m_right;
}					t_mlx;

t_mlx				*init_mlx(void);
void				set_wolf(t_wolf *wolf, int x);
void				draw_wolf(t_wolf *wolf, t_mlx *mlx);
void				get_dist_wall(t_wolf *wolf);
void				ray_cast(t_wolf *wolf);
void				get_wall_size(t_wolf *wolf);
int					get_loop(t_mlx *mlx);
void				start_hook(t_mlx *mlx);
void				cursor_move(t_mlx *mlx, int dir, double diff);
void				forward_and_backward(t_wolf *wolf, int dir);
void				left_and_right(t_wolf *wolf, int dir);
int					disable_key(int keycode, t_mlx *mlx);
int					enable_key(int keycode, t_mlx *mlx);
int					mouse_hook(int x, int y, t_mlx *mlx);
int					mouse_key_hook(int keycode, int x, int y, t_mlx *mlx);
int					red_cross_hook(void *param);
int					select_hook(int keycode, t_mlx *mlx);
void				display_xpm(char *path, t_mlx *mlx, int start);
t_wolf				*init_wolf(void);
int					redraw_wolf(t_mlx *mlx);
int					**get_map(int fd, char *filename, t_wolf *wolf);
int					get_color(int xory, double rayx, double rayy);
void				get_spawn(t_wolf *wolf);
int					check_map(t_wolf *wolf);
int					wtd_error(int err, t_wolf *wolf);
void				use_custom_map(char *av, t_wolf *wolf, t_mlx *mlx);
void				select_map_menu(t_wolf *wolf, t_mlx *mlx);

#endif
