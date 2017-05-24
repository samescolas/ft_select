/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:55:55 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/24 11:51:38 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_select.h"
#include "ft_types.h"

int		get_term_width(void)
{
	int	ret;

	if ((ret = tgetnum("co")) > 0)
		return (ret);
	return (0);
}

int		get_term_height(void)
{
	int	ret;

	if ((ret = tgetnum("li")) > 0)
		return (ret);
	return (0);
}

int		check_term_height(t_window win)
{
	int		rows;
	size_t	height;

	rows = ft_ceil(win.num_args, win.num_cols);
	height = win.border_top;
	height = rows * win.box_height;
	height += (rows - 1) * win.v_padding;
	return (height <= win.term_height);
}

int		check_term_width(t_window win)
{
	size_t	width;

	width = win.num_cols * win.box_width;
	width += (win.num_cols - 1) * win.h_padding;
	return (width <= win.term_width);
}
