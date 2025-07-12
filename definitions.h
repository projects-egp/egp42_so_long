/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:28:20 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/12 03:12:29 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include "general.h"

# define EXPECTED_FORMAT "maps/<name-of-map-file>.ber"
# define GAME_NAME "FLY AWAY, HILARIO!"
//
/*	* SIZES values 	*	*/
# define MIN_MAP_SIZE 15// == (3 * 5)
# define MAX_MAP_SIZE 1920// == (77 * 40)
# define PICTURE_SIZE 64
//
/*	* ERROR_FLAG values 	*	*/
# define WRONG_P 1
# define WRONG_E 2
# define WRONG_C 3
# define WRONG_SIZE 4
# define WRONG_WALL 5
# define WRONG_CHAR 6
# define EMPTY_FILE 7
# define CANNOT_WIN_GAME 8
//
/*	*    TEXTURES PATHS 	*	*/
# define GRASS "./textures/grass.xpm"
# define ITEM "./textures/item.xpm"
# define PILOT_DOWN "./textures/pilot_down.xpm"
# define PILOT_LEFT "./textures/pilot_left.xpm"
# define PILOT_RIGHT "./textures/pilot_right.xpm"
# define PILOT_UP "./textures/pilot_up.xpm"
# define PLANE "./textures/plane.xpm"
# define PLANE_REPAIRED "./textures/plane_repaired.xpm"
# define TREE "./textures/tree.xpm"
//
/*	*    TEXTURES PATHS 	*	*/
# define UP 119 
# define RIGHT 100
# define DOWN 115
# define LEFT 97
# define ESC 65307

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		p_position[2];
	int		e_position[2];
	int		p_flag;
	int		c_flag;
	int		e_flag;
	int		error_flag;
}	t_map;

typedef struct s_mlx
{
	t_map	*map_data;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_grass;
	void	*img_item;
	void	*img_pilot_down;
	void	*img_pilot_left;
	void	*img_pilot_right;
	void	*img_pilot_up;
	void	*img_plane;
	void	*img_plane_repaired;
	void	*img_tree;
	int		moves;
}	t_mlx;

#endif
