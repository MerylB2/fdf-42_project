/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiatik <asiatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:41:17 by asiatik           #+#    #+#             */
/*   Updated: 2025/01/19 22:02:47 by asiatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ---- includes/fdf.h ---- */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 800
# define ZOOM_DEFAULT 30


int ft_parse_map(char *filename, int **map_values, int *width, int *height);
void ft_draw_map(int **map_values, int width, int height);
int ft_handle_key(int key, void *param);
int ft_close_window(void *param);

#endif