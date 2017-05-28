/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_window.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:49:21 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/27 11:52:47 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_types.h"
#include "ft_terminfo.h"

t_window	*ft_create_window(int num_args)
{
	t_window	*ret;

	if (!(ret = (t_window *)malloc(sizeof(t_window))))
		ft_fatal("err: out of memory\n\r");
	ret->term_width = get_term_width();
	ret->term_height = get_term_height();
	ret->border_top = 0;
	ret->border_left = 0;
	ret->num_cols = 1;
	ret->num_args = num_args;
	ret->h_padding = 1;
	ret->v_padding = 0;
	ret->box_width = 0;
	ret->box_height = 0;
	return (ret);
}

void		reset_window(t_window *win)
{
	win->num_cols = 1;
	win->h_padding = 1;
	win->v_padding = 0;
	win->border_top = 0;
	win->border_left = 0;
	win->term_width = get_term_width();
	win->term_height = get_term_height();
}

void		free_window(t_window *win)
{
	free(win);
	win = (void *)0;
}
