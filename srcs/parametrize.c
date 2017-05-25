/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parametrize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:39:14 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/25 09:40:23 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"

t_choice	*parametrize_options(char **arr, t_window *win)
{
	t_choice	*list;
	t_coord		*pos;
	size_t		args_added;

	args_added = -1;
	list = (void *)0;
	pos = create_coord(win->border_left + 1, win->border_top + 1);
	while (++args_added < win->num_args)
	{
		choice_add(&list, create_choice(arr[args_added], pos));
		if (args_added > 0 && (args_added + 1) % win->num_cols == 0)
		{
			pos->x = win->border_left + 1;
			pos->y += (win->box_height + win->h_padding);
		}
		else
			pos->x += (win->box_width + win->v_padding);
	}
	return (list);
}
