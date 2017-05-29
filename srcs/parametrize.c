/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parametrize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:39:14 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/28 13:55:33 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "../libft/libft.h"

t_choice	*find_list_beginning(t_choice **list, char **choices)
{
	t_choice	*ret;
	size_t		arg;

	ret = *list;
	arg = 0;
	while (!ft_strequ(ret->label, choices[arg]))
	{
		ret = ret->next;
		if (*list == ret)
			++arg;
	}
	return (ret);
}

t_choice	**reassign_coords(t_choice ***list, char **choices, t_window *win)
{
	t_choice	**ret;
	t_choice	*tmp;
	t_coord		*pos;
	int			args_added;

	args_added = -1;
	ret = *list;
	tmp = find_list_beginning(*list, choices);
	pos = create_coord(win->border_left, win->border_top);
	while (++args_added < (int)(win->num_args))
	{
		tmp->position->x = pos->x;
		tmp->position->y = pos->y;
		if (win->num_cols == 1 ||\
				(args_added > 0 && (args_added + 1) % win->num_cols == 0))
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

t_choice	**parametrize_choices(char **choices, t_window *win)
{
	t_choice	**list;
	t_coord		*pos;
	size_t		args_added;

	args_added = -1;
	list = (void *)0;
	if (!(list = (t_choice **)malloc(sizeof(t_choice **))))
		ft_fatal("err: out of memory\n\r");
	*list = (void *)0;
	pos = create_coord(win->border_left, win->border_top);
	while (++args_added < win->num_args)
	{
		choice_add(list, create_choice(choices[args_added], pos));
		if (win->num_cols == 1\
			|| (args_added > 0 && (args_added + 1) % win->num_cols == 0))
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
