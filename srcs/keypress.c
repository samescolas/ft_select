/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:39:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/28 14:34:32 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "ft_display.h"
#include "ft_termcap.h"
#include "ft_atexit.h"
#include "../libft/libft.h"

static void	handle_arrowkeys(char c, t_window *win, t_choice **list)
{
	size_t	i;

	i = win->num_cols;
	if (c == 'A' || c == 'k')
		while (i--)
			*list = (*list)->prev;
	else if (c == 'B' || c == 'j')
		while (i--)
			*list = (*list)->next;
	else if (c == 'C' || c == 'l')
		*list = (*list)->next;
	else if (c == 'D' || c == 'h')
		*list = (*list)->prev;
	print_list(*list);
}

static void	handle_backspace(t_window *win, t_choice ***list, char **args)
{
	if (**list == (**list)->next)
	{
		remove_choice(*list);
		ft_atexit();
	}
	else
	{
		win->num_args--;
		remove_choice(*list);
		redisplay(list, win, args, 1);
	}
}

static void	handle_escape(t_window *win, t_choice ***list, char **args)
{
	int		ret;
	char	c;

	if ((ret = read(STDIN_FILENO, &c, 1)) > 0 && c == '[')
	{
		if ((ret = read(STDIN_FILENO, &c, 1)) > 0)
		{
			if (c >= 'A' && c <= 'D')
				handle_arrowkeys(c, win, *list);
			else if (c == '3')
				handle_backspace(win, list, args);
			else
				write(1, &c, 1);
		}
	}
	else
	{
		free_choices(*list);
		free_window(win);
		ft_atexit();
	}
}

static void	return_to_shell(t_choice *list)
{
	t_choice	*start;
	size_t		first;

	start = list;
	first = 1;
	list = list->next;
	if (start->selected)
	{
		ft_putstr(start->label);
		first = 0;
	}
	while (list != start)
	{
		if (list->selected)
		{
			if (!first)
				write(1, " ", 1);
			ft_putstr(list->label);
			first = 0;
		}
		list = list->next;
	}
}

void		ft_keypress(char c, t_window *win, t_choice ***list, char **args)
{
	if (c == 27)
		handle_escape(win, list, args);
	else if (c == ' ')
	{
		(**list)->selected = !((**list)->selected);
		(**list) = (**list)->next;
		print_list(**list);
	}
	else if (c == 'h' || c == 'j' || c == 'k' || c == 'l')
		handle_arrowkeys(c, win, *list);
	else if (c == 127)
		handle_backspace(win, list, args);
	else if (c == 13)
	{
		ft_clear_screen();
		return_to_shell(**list);
		free_choices(*list);
		free_window(win);
		ft_atexit();
	}
	else if (c == 'q')
		ft_atexit();
}
