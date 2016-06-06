/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 02:57:56 by rle-mino          #+#    #+#             */
/*   Updated: 2016/05/26 22:03:46 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wtd.h"

size_t			array_len(char **array)
{
	size_t	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

int				*str_to_array(char *str, t_wolf *wolf, int fd)
{
	int		i;
	char	**tab;
	int		*array;

	i = -1;
	tab = ft_strsplit(str, ' ');
	if (wolf->size_map_x && (size_t)wolf->size_map_x != array_len(tab))
	{
		wtd_error(MAP, wolf);
		close(fd);
	}
	wolf->size_map_x = array_len(tab);
	array = (int*)ft_memalloc(sizeof(int) * array_len(tab));
	while (tab[++i])
	{
		if (!ft_isdigit(tab[i][0]))
			return (NULL);
		array[i] = ft_atoi(tab[i]);
		free(tab[i]);
	}
	free(tab);
	return (array);
}

int				get_map_size(int *fd, char *filename, t_wolf *wolf)
{
	char	*buffer;

	while (get_next_line(*fd, &buffer) > 0)
	{
		wolf->map_line++;
		if (!ft_isdigit(buffer[0]) && buffer[0] != ' ')
		{
			close(*fd);
			wtd_error(MAP, wolf);
		}
		free(buffer);
	}
	free(buffer);
	close(*fd);
	*fd = open(filename, O_RDONLY);
	return (wolf->map_line);
}

int				**get_map(int fd, char *filename, t_wolf *wolf)
{
	int			**tab;
	int			i;
	char		*buffer;

	i = 0;
	tab = ft_memalloc(sizeof(int *) * (get_map_size(&fd, filename, wolf) + 1));
	while (get_next_line(fd, &buffer) > 0)
	{
		if (!(tab[i] = str_to_array(buffer, wolf, fd)))
			return (NULL);
		i++;
		free(buffer);
	}
	close(fd);
	free(buffer);
	if (wolf->size_map_x < 3 || wolf->map_line < 3)
		wtd_error(SMALL, wolf);
	return (tab);
}
