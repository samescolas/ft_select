/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:36:26 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/29 11:01:31 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "ft_atexit.h"
#include "ft_types.h"
#include "ft_signal.h"
#include "ft_termcap.h"
#include "ft_terminfo.h"
#include "../libft/libft.h"

static void		reset_terminal_settings(struct termios *original_settings)
{
	static struct termios	saved_settings;

	if (original_settings)
		ft_memcpy(\
			&saved_settings, original_settings, sizeof(*original_settings));
	else
		tcsetattr(STDIN_FILENO, 0, &saved_settings);
}

void			ft_makeraw(void)
{
	struct termios	settings;

	if (!isatty(STDIN_FILENO))
		ft_fatal("err: not a terminal\n");
	tcgetattr(STDIN_FILENO, &settings);
	reset_terminal_settings(&settings);
	settings.c_iflag &= ~(ICRNL | IXON);
	settings.c_oflag &= ~(OPOST);
	settings.c_lflag &= ~(ECHO | ICANON | IEXTEN);
	settings.c_cc[VMIN] = 0;
	settings.c_cc[VTIME] = 1;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &settings) == -1)
		ft_fatal("err: unable to enter raw mode\n");
}

void			reset_terminal(void)
{
	reset_terminal_settings((void *)0);
}

t_window		*load_terminal(int num_args, char **args)
{
	char		*termtype;
	char		*buff;
	int			status;
	t_window	*win;

	win = (void *)0;
	if (num_args <= 0 && num_args != -1742)
		ft_fatal("err: please include menu options\n");
	termtype = (void *)0;
	if (!(buff = (char *)malloc(2048 * sizeof(char))))
		ft_fatal("err: out of memory\n");
	if (!(termtype = getenv("TERM")))
		ft_fatal("err: terminal type unavailable\n");
	if ((status = tgetent(buff, termtype)) <= 0)
		ft_fatal("err: unable to load terminal\n");
	ft_makeraw();
	if (num_args == -1742)
		return ((void *)0);
	ft_str_atexit(1, buff);
	ft_func_atexit(1, &reset_terminal);
	ft_func_atexit(1, &reset_signals);
	ft_func_atexit(1, &ft_show_cursor);
	ft_func_atexit(1, &ft_clear_screen);
	dimensionalize(args, (win = ft_create_window(num_args)), 0);
	return (win);
}
