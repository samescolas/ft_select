/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:30:52 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/29 10:30:36 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "ft_display.h"
#include "ft_terminfo.h"
#include "ft_termcap.h"
#include "init.h"
#include "../libft/libft.h"

void	print_list(t_choice *list)
{
	t_choice	*tmp;

	tmp = list->next;
	display_choice(*list, 1);
	while (tmp != list)
	{
		display_choice(*tmp, tmp == list);
		tmp = tmp->next;
	}
	display_choice(*tmp, tmp == list);
}

void	redisplay(t_choice ***list, t_window *win, char **args, int preserve)
{
	int		num_cols;

	num_cols = (preserve ? win->num_cols : 0);
	if (!preserve)
		reset_window(win);
	dimensionalize(args, win, num_cols);
	*list = reassign_coords(list, args, win);
	ft_clear_screen();
	print_list(**list);
}

void	launch_menu(int num_choices, char **choices)
{
	static t_choice	**list;
	static t_window	*win;
	int				ret;
	char			c;

	if (num_choices > 0)
		win = load_terminal(num_choices, choices);
	else
		load_terminal(num_choices, choices);
	if (num_choices > 0)
		list = parametrize_choices(choices, win);
	ft_clear_screen();
	ft_hide_cursor();
	print_list(*list);
	while (1742)
	{
		if (screen_size_changed(win))
			redisplay(&list, win, choices, 0);
		if ((ret = read(STDIN_FILENO, &c, 1)) > 0)
			ft_keypress(c, win, &list, choices);
	}
}
