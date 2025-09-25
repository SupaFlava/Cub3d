/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/23 13:07:58 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/09/25 17:32:58 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		print_and_exit(int code) // make this into a clean exit function later instead of
{
	if (code == INIT_FAILURE)
	{
		ft_printf("mlx_init failed");
		return (code);
	}
	return (0);
}

void	keyhook(mlx_key_data_t keydata, void* param) // registers escape key only for now
{
	(void)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_printf("escape key pressed\n");
		exit(EXIT_SUCCES);
	}
}

int	main(/*int argc, char *argv[]*/) //no parameters given yet at launch
{
	mlx_t *mlx;
	mlx_image_t *img;

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "w0ffelstein", true);
	if (!mlx)
		return (print_and_exit(INIT_FAILURE));

	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	memset(img->pixels, 255, img->width * img->height * BPP);
	mlx_image_to_window(mlx, img, 0, 0);

	mlx_key_hook(mlx, &keyhook, NULL);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCES);
}