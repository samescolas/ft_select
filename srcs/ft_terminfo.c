/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:55:55 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/28 12:31:22 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "ft_terminfo.h"
#include "../libft/libft.h"

size_t	get_content_height(t_window win)
{
	size_t	height;
	size_t	num_rows;

	num_rows = ft_ceil(win.num_args, win.num_cols);
	height = win.border_top;
	height += (num_rows * win.box_height);
	height += (win.num_args * win.v_padding);
	return (height);
}

size_t	get_content_width(t_window win)
{
	size_t	width;

	width = win.border_left;
	width += (win.num_cols * win.box_width);
	width += (win.num_cols * win.h_padding);
	return (width);
}

size_t	check_term_height(t_window win)
{
	return (get_content_height(win) < get_term_height());
}

size_t	check_term_width(t_window win)
{
	return (get_content_width(win) < get_term_width());
}
