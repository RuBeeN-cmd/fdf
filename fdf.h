/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:28:49 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/16 17:20:14 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define PI 3.14159265

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}				t_point;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_point	***matrix;
	void	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	int		width;
	int		height;
	float	zoom;
	int		offset_x;
	int		offset_y;
	int		mouse_1;
	int		mouse_2;
	int		initial_x;
	int		initial_y;
	int		mode;
}				t_vars;

// error.c
void	ft_free_double_tab(void **tab);
void	ft_error(char *msg);
void	ft_test_fd(t_vars *vars, int fd);

// ft_parse.c
void	ft_free_to_null(t_point ***matrix);
int		ft_hex_to_int(char *nb);
void	ft_parse_cell(t_point ***matrix, char *cell, int i, int j);
void	ft_parse_line(t_point ****matrix, char *line, int i);
t_point	***ft_parse(t_vars *vars, char *path);

// ft_sphere.c
void	ft_convert_sphere(t_point ***matrix);

// hook.c
int		ft_motion(int x, int y, t_vars *vars);
int		ft_mouse(int button, int x, int y, t_vars *vars);
int		ft_close(t_vars *vars);
int		hook(int keycode, t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);

// image.c
void	ft_init_image(t_vars *vars);
void	ft_pixel_put(t_vars *vars, int x, int y, int color);
void	ft_create_image(t_vars *vars);
void	ft_get_new_frame(t_vars *vars);

// limits.c
void	ft_check_limits(t_point *point, int *limits);
void	ft_get_limits(t_vars *vars, int *limits);
void	ft_update_matrix(t_vars *vars, int *limits);

// rotation.c
void	ft_rotate_x(t_point *point, float theta);
void	ft_rotate_y(t_point *point, float theta);
void	ft_rotate_z(t_point *point, float theta);
void	ft_rotate(t_vars *vars, float theta, void (*rotation)(t_point*, float));

// segment.c
int		ft_get_color(t_point *a, t_point *b, int step, int total_step);
void	ft_swap_point(t_point *a, t_point *b);
void	ft_draw_segment(t_vars *vars, t_point point1, t_point point2);
int		ft_segment_is_visible(t_vars *vars, t_point point1, t_point point2);
void	ft_update_points(t_vars *vars, t_point *point1, t_point *point2);

// segment_bis.c
void	ft_segment_dx(t_vars *vars, t_point point1, t_point point2);
void	ft_segment_dy(t_vars *vars, t_point point1, t_point point2);

// vars.c
void	ft_init_values(t_vars *vars, int width, int height, int mode);
void	ft_set_hook(t_vars *vars);
t_vars	*ft_init_vars(char *path, int width, int height, int mode);
void	ft_free_data(t_vars *vars);

#endif
