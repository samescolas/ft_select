/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parametrize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:39:14 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/27 10:54:06 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "../libft/libft.h"

t_choice	**reassign_coordinates(t_choice ***list, char **arr, t_window *win)
{
	int			args_added;
	t_choice	**ret;
	t_coord		*pos;
	t_choice	*tmp;
	int			arg;

	args_added = -1;
	pos = create_coord(win->border_left, win->border_top);
	tmp = **list;
	ret = *list;
	arg = 0;
	while (!ft_strequ(tmp->label, arr[arg]))
	{
		tmp = tmp->next;
		if (**list == tmp)
			++arg;
	}
	while (++args_added < (int)(win->num_args))
	{
		tmp->position->x = pos->x;
	   	tmp->position->y = pos->y;
		if (win->num_cols == 1 || (args_added > 0 && (args_added + 1) % win->num_cols == 0))
		{
			pos->x = win->border_left;
			pos->y += (win->box_height + win->v_padding);
		}
		else
			pos->x += (win->box_width + win->h_padding);
		tmp = tmp->next;
	}
	uncoordinate(pos);
	return (ret);
}

t_choice	*parametrize_options(char **arr, t_window *win)
{
	t_choice	*list;
	t_coord		*pos;
	size_t		args_added;

	args_added = -1;
	list = (void *)0;
	pos = create_coord(win->border_left, win->border_top);
	while (++args_added < win->num_args)
	{
		choice_add(&list, create_choice(arr[args_added], pos));
		if (win->num_cols == 1 || (args_added > 0 && (args_added + 1) % win->num_cols == 0))
		{
			pos->x = win->border_left;
			pos->y += (win->box_height + win->v_padding);
		}
		else
			pos->x += (win->box_width + win->h_padding);
	}
	uncoordinate(pos);
	return (list);
}
