/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parametrize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:39:14 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/26 16:58:12 by sescolas         ###   ########.fr       */
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

	ft_putstr("inside reassign_coords\n\r");
	args_added = -1;
	pos = create_coord(win->border_left, win->border_top);
	tmp = **list;
	ret = *list;
	ft_putstr("looking for beginning of string\n\r");
	while (!ft_strequ(tmp->label, arr[0]))
	{
		ft_putstr("searching for beginning...\n\r");
		tmp = tmp->next;
	}
	ft_putstr("found beginning!\n\r");
	while (++args_added < (int)(win->num_args))
	{
		tmp->position->x = pos->x;
	   	tmp->position->y = pos->y;
		ft_putstr("created!\n\rchecking to see if we're at the end of a row\n\r");
		if (win->num_cols == 1 || (args_added > 0 && (args_added + 1) % win->num_cols == 0))
		{
			ft_putstr("new row!\n\r");
			pos->x = win->border_left;
			pos->y += (win->box_height + win->v_padding);
		}
		else
		{
			ft_putstr("next column!\n\r");
			pos->x += (win->box_width + win->h_padding);
		}
		tmp = tmp->next;
	}
	ft_putstr("updated all coords!\n\r");
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
