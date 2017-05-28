/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:30:52 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/27 18:03:00 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "ft_display.h"
#include "ft_terminfo.h"
#include "parametrize.h"
#include "ft_termcap.h"
#include "../libft/libft.h"
#include "init.h"

void		handle_keypress(char c, t_window *win, t_choice ***list, char **args);
t_choice	**reassign_coordinates(t_choice ***list, char **arr, t_window *win);

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
	*list = reassign_coordinates(list, args, win);
	ft_clear_screen();
	print_list(**list);
}

void	launch_menu(t_choice **list, t_window *win, char **args)
{
	int		ret;
	char	c;

	ft_clear_screen();
	print_list(*list);
	while (1)
	{
		if (screen_size_changed(win))
			redisplay(&list, win, args, 0);
		if ((ret = read(STDIN_FILENO, &c, 1)) > 0)
			handle_keypress(c, win, &list, args);
	}
}
