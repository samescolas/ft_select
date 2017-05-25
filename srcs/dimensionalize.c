/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensionalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:53:46 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/25 09:00:58 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_types.h"
#include "ft_terminfo.h"

static int	get_max_length(char **arr)
{
	int		max;
	int		len;
	int		i;

	i = 0;
	max = ft_strlen(arr[i]);
	while (arr[++i])
		if ((len = ft_strlen(arr[i])) > max)
			max = len;
	return (max);
}

void		test_dimensions(char **arg_list, t_window *win)
{
	if ((win->box_width = get_max_length(arg_list)) > win->term_width)
	{
		win->box_height = ft_ceil(win->box_width, win->term_width);
		if (win->box_height * win->num_args > win->term_height)
			ft_fatal("err: terminal window too small\n\r");
	}
	else
	{
		win->box_height = 1;
		while (check_term_width(*win) && !check_term_height(*win))
			++(win->num_cols);
		if (!check_term_width(*win) || !check_term_height(*win))
			ft_fatal("err: terminal window too small\n\r");
	}
}

static void	add_horizontal_padding(t_window *win)
{
	double	pct;
	double	content_width;

	pct = 0;
	while (pct < 0.9)
	{
		content_width = (double)get_content_width(*win);
		pct = (double)(content_width / (double)win->term_width);
		win->h_padding++;
	}
	win->border_left = (win->term_width - get_content_width(*win)) / 2;
}

static void	add_vertical_padding(t_window *win)
{
	double	pct;
	double	content_height;

	pct = 0;
	while (pct < 0.9)
	{
		content_height = (double)get_content_height(*win);
		pct = (double)(content_height / (double)win->term_height);
		if (win->border_top++ % 10 == 0)
			win->v_padding++;
	}
	win->border_top /= 2;
}

int			perfect_square(int num_args)
{
	int		n;

	n = 4;
	while (n < num_args)
	{
		if (num_args % n == 0)
			return (n);
		n *= 2;
	}
	return (0);
}

void		dimensionalize(t_window *win)
{
	size_t	goal_seek;

	goal_seek = 0;
	if ((goal_seek = (size_t)perfect_square(win->num_args)))
		win->num_cols = goal_seek;
	else if (win->num_args > 1)
	{
		goal_seek = 2;
		while (goal_seek < win->num_args && win->num_args % goal_seek)
			++goal_seek;
	}
	if (goal_seek > 0 && win->num_args % goal_seek == 0)
		win->num_cols = goal_seek;
	add_vertical_padding(win);
	if (win->num_args > 1)
		add_horizontal_padding(win);
}
