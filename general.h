/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:46:08 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/12 01:07:29 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/complete_libft.h"
# include "definitions.h"

void	map_format(char *map_path);
int		open_map(char *map_pathname, t_map *map_data);
void	check_line_by_line(int fd, t_map *map_data, t_list **lines);
/*	*	manage_error	*	*/
void	print_error(t_map *map_data);
void	close_clean_and_exit_error(int fd, char *read_line,
			t_list **lines_list, t_map *data);
/*	*	parse_utils*	*/
int		check_width(char *line, t_map *data);
void	add_new_line(char *read_line, t_list **lines_list, t_map *data);
/*	*	manage_window	*	*/
int		create_window(t_map *map_data, t_mlx *mlx_data);
void	print_map(t_map *map_data, t_mlx *mlx_data);
int		key_press(int key, t_mlx *mlx);
void	print_moves(int moves);
void	choose_tile_to_print(t_mlx *mlx, char **map, int x, int y);
void	special_event(t_map *data, char target);
void	rotate_player(int key, int x, int y, t_map *player);
char	set_target(int key, int x, int y, char **map);
void	execute_move(int key, int x, int y, t_map *data);

#endif
