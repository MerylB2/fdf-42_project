/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiatik <asiatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:33:10 by asiatik           #+#    #+#             */
/*   Updated: 2025/01/14 22:42:38 by asiatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define ISO_ANGLE 0.523599

/* Codes des touches pour Linux */

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 65451
# define KEY_MINUS 65453

/* Couleurs */

# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

/* Gestion d'erreurs */
# define ERR_USAGE "Usage: ./fdf <filename.fdf>"
# define ERR_MAP "Error: Invalid map file"
# define ERR_MALLOC "Error: Memory allocation failed"
# define ERR_FD "Error: Cannot open file"

/* PROTOTYPES */

/* map_reader.c */

int	count_width(char *line);
int	get_map_size(char *filename, int *width, int *height);
int	*parse_line(char *line, int width);
int **map_read(char *filename, int *width, int *height);

/* draw.c */

void	draw_line(void *mlx, void *win, int *start, int *end);
void	iso_project(int *x, int *y, int z);
void	draw_map(void *mlx, void *win, int **map, int *size);

/* fdf_utils.c */

void	free_map(int **map, int height);
int	key_press(int keycode, void *parm);
void	error_exit(char *message);
int	absolute(int n);
void	clean_split(char **split);

/* main.c */
int main(int argc, char **argv);

/* Error handling */

# define CHECK_NULL(x, msg) if (!(x)) error_exit(msg)
# define CHECK_FD(x, msg) if ((x) < 0) error_exit(msg)
# define CHECK_ERROR(x, msg) if (!(x)) error_exit(msg)

#endif