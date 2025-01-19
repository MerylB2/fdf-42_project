/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiatik <asiatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:56:35 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/19 22:15:01 by asiatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	free_map(int **map, int height)
{
	int	i;

	if (map)
	{
		i = 0;
		while (i < height)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

int	key_press(int keycode, void *param)
{
	void	**params;

	params = (void **)param;
	if (keycode == 65307) // ESC key on Linux
	{
		mlx_destroy_window(params[0], params[1]);
		exit(0);
	}
	return (0);
}
