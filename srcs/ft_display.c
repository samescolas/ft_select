/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:30:52 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/26 16:54:42 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "ft_display.h"
#include "ft_terminfo.h"
#include "parametrize.h"
#include "dimensionalize.h"
#include "ft_termcap.h"
#include "../libft/libft.h"

void		handle_ctrl(char c, t_window *win, t_choice **list);
void		handle_keypress(char c, t_window *win, t_choice **list);
t_choice	**reassign_coordinates(t_choice ***list, char **arr, t_window *win);

void		print_list(t_choice *list)
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

static void	redisplay_menu(t_choice ***list, t_window *win, char **args)
{

	reset_window(win);
	dimensionalize(args, win);
	*list = reassign_coordinates(list, args, win);
	//list = parametrize_options(args, win);
	ft_clear_screen(*win);
	print_list(**list);
}

void		launch_menu(t_choice **list, t_window *win, char **args)
{
	int		ret;
	char	c;

	print_list(*list);
	while (1)
	{
		if (screen_size_changed(win))
			redisplay_menu(&list, win, args);
		if ((ret = read(STDIN_FILENO, &c, 1)) > 0)
		{
			if (c == 27 && (ret = read(STDIN_FILENO, &c, 1)) > 0  && c == '[')
				handle_ctrl(c, win, list);
			else
				handle_keypress(c, win, list);
		}
	}
}
