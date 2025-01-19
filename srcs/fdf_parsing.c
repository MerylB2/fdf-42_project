/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiatik <asiatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:04:51 by asiatik           #+#    #+#             */
/*   Updated: 2025/01/19 22:09:11 by asiatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_width(char *line)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (line[i])
	{
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		while (line[i] && line[i] != ' ' && line[i] != '\t')
			i++;
	}
	return (width);
}

int	get_map_size(char *filename, int *width, int *height)
{
	int		fd;
	char	*line;

	*height = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		retrun (0);
	while (get_next_line(fd, &line) > 0)
	{
		if (*height == 0)
			*width = count_width(line);
		(*height)++;
		free(line);
	}
	close (fd);
	return (1);
}

int	*parse_line(char *line, int width)
{
	int		*row;
	char	**split;
	int		i;

	row = malloc(sizeof(int) * width);
	if (!row)
		return (NULL);
	split = ft_split(line, ' ');
	if (!split)
	{
		free(row);
		return (NULL);
	}
	i = 0;
	while (i < width && split[i])
	{
		row[i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (row);
}

int	**read_map(char *filename, int *width, int *height)
{
	int		**map;
	int		fd;
	char	*line;
	int		i;

	if (!get_map_size(filename, width, height))
		return (NULL);
	map = malloc(sizeof(int *) * (*height));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		map[i] = parse_line(line, *width);
		if (!map)
		{
			while (i > 0)
				free(map[--i]);
			free(map);
			free(line);
			close(fd);
			return (NULL);
		}
		free(line);
		i++;
	}
	return (close (fd), map);
}
