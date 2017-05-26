/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:55:55 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/25 12:03:39 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_select.h"
#include "ft_types.h"

size_t	get_term_width(void)
{
	int	ret;

	if ((ret = tgetnum("co")) > 0)
		return (ret);
	return (0);
}

size_t	get_term_height(void)
{
	int	ret;

	if ((ret = tgetnum("li")) > 0)
		return (ret);
	return (0);
}

size_t	get_content_height(t_window win)
{
	size_t	height;
	size_t	num_rows;

	num_rows = ft_ceil(win.num_args, win.num_cols);
	height = win.border_top;
	height += (num_rows * win.box_height);
	height += ((win.num_args - 1) * win.v_padding);
	return (height);
}

size_t	get_content_width(t_window win)
{
	size_t	width;

	width = win.border_left;
	width += (win.num_cols * win.box_width);
	width += ((win.num_cols - 1) * win.h_padding);
	return (width);
}

int		check_term_height(t_window win)
{
	return (get_content_height(win) <= win.term_height);
}

int		check_term_width(t_window win)
{
	return (get_content_width(win) <= win.term_width);
}
