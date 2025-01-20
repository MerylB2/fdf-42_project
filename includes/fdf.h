/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiatik <asiatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:44:58 by asiatik           #+#    #+#             */
/*   Updated: 2025/01/20 19:55:37 by asiatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h" // Assurez-vous que votre libft est bien incluse ici.

# define ISO_ANGLE 0.523599 // 30° en radians
# define ESC_KEY 65307      // Code de la touche ESC (Linux)

/* Représentation d'un point dans l'espace avec ses coordonnées (x, y, z) */
/* et sa couleur */
typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

/* Les dimensions de la carte (rows, cols) et les points correspondants */
typedef struct s_map
{
	size_t	rows;
	size_t	cols;
	t_point	**points;
}	t_map;

/* Gestion d'image créée avec MiniLibX */
typedef struct s_img
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

/* Structure principale contenant MiniLibX, la carte et l'image */
typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_img	*img;
}	t_data;

/* Parsing : Chargement et lectures de données du fichier .fdf en mémoire. */
char	**read_file(const char *file);
t_map	*parse_map(char **lines);
size_t	count_lines(char **lines);
size_t	count_columns(char *line);
void	parse_line(char *line, t_map *map, size_t row);
void	free_split(char **split);

/*Projection isometrique : Convertion les coordonnées (x, y, z)pour une vue*/
/*isométrique et implémentation des formules de rotation et de projection.*/
void	proj_isometric(t_point *point);

/* Rendering : Dessin de segments entre les points à l'aide de MiniLibX*/
void	draw_line(t_data *data, t_point start, t_point end);
void	render_map(t_data *data);

/* Events :Fermeture de la fenêtre avec ESC ou clic sur la croix */
int		handle_key(int key, t_data *data);
int		close_window(t_data *data);

//* Utils : gestion de l'absence de fuites mémoire et des erreurs*/
void	*safe_malloc(size_t size);
void	error_exit(const char *message);
void	clean_exit(t_data *data);
t_map	*allocate_map(size_t rows, size_t cols);
t_point	**allocate_points(size_t rows, size_t cols);
void	free_map(t_map *map);
void	free_resources(t_data *data);

#endif
