/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmhazres <rmhazres@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 23:02:13 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/01 21:22:29 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "MLX42_Int.h"
# include "libft.h"

# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# include "typedefs.h"
# include "parsing.h"
# include "validate.c"
# include "game.h"
# include "utils.h"
# include "render.h"
# include "utils.h"



# define FAILURE 0
# define SUCCESS 1
# define BUFF 1024

// defines
# define WIDTH 1920
# define HEIGHT 1080

# define TILE_SIZE 64
# define INIT_FAILURE 2
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

#endif // CUB3D_H