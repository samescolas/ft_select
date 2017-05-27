/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensionalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:53:46 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/26 15:13:53 by sescolas         ###   ########.fr       */
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

static void	test_dimensions(char **arg_list, t_window *win)
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

void		dimensionalize(char **argv, t_window *win)
{
	size_t	goal_seek;
	size_t	tmp;

	test_dimensions(argv, win);
	goal_seek = 0;
	if ((goal_seek = (size_t)perfect_square(win->num_args)) && goal_seek > win->num_cols)
	{
		tmp = win->num_cols;
		win->num_cols = goal_seek;
	}
	if ((!check_term_width(*win) || !check_term_height(*win)) && win->num_args > 1)
	{
		win->num_cols = tmp;
		goal_seek = 2;
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
	}
	add_vertical_padding(win);
	add_horizontal_padding(win);
}
