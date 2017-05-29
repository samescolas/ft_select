/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensionalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:53:46 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/29 10:49:56 by sescolas         ###   ########.fr       */
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
	return (max % 2 == 0 ? max + 1 : max);
}

static void	test_dimensions(char **arg_list, t_window *win)
{
	if ((win->box_width = get_max_length(arg_list)) > win->term_width)
	{
		win->box_height = ft_ceil(win->box_width, win->term_width);
		if (win->box_height * win->num_args > win->term_height)
			wait_for_larger_window(arg_list, win);
	}
	else
	{
		win->box_height = 1;
		while (check_term_width(*win) && !check_term_height(*win))
			++(win->num_cols);
		if (!check_term_width(*win) || !check_term_height(*win))
			wait_for_larger_window(arg_list, win);
	}
}

static void	add_horizontal_padding(t_window *win)
{
	double	pct;
	double	content_width;

	pct = 0;
	while (pct < 0.75)
	{
		content_width = (double)get_content_width(*win);
		pct = (double)(content_width / (double)win->term_width);
		if (win->num_cols == 1)
			break ;
		win->h_padding++;
	}
	while (!check_term_width(*win))
		win->h_padding--;
	if (check_term_width(*win))
		win->border_left = (win->term_width - get_content_width(*win)) / 2;
}

static void	add_vertical_padding(t_window *win)
{
	double	pct;
	double	content_height;

	pct = 0;
	while (pct < 0.75 && win->v_padding < win->box_width)
	{
		content_height = (double)get_content_height(*win);
		pct = (double)(content_height / (double)win->term_height);
		if (ft_ceil(win->num_args, win->num_cols) == 1)
			break ;
		win->v_padding++;
	}
	while (!check_term_height(*win))
		win->v_padding--;
	if (check_term_height(*win))
		win->border_top = (win->term_height - get_content_height(*win)) / 2;
}

void		dimensionalize(char **argv, t_window *win, int num_cols)
{
	size_t	goal_seek;
	size_t	tmp;

	test_dimensions(argv, win);
	goal_seek = 1;
	while (goal_seek < win->num_args && win->num_args % goal_seek)
	{
		tmp = win->num_cols;
		win->num_cols = goal_seek;
		if (!check_term_width(*win) || !check_term_height(*win))
		{
			win->num_cols = tmp;
			break ;
		}
		++goal_seek;
	}
	if (num_cols)
		win->num_cols = num_cols;
	else
	{
		add_vertical_padding(win);
		add_horizontal_padding(win);
	}
}
