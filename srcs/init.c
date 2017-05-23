/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:36:26 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/23 14:37:34 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "ft_atexit.h"
#include "../libft/libft.h"

void			reset_terminal_settings(struct termios *original_settings)
{
	static struct termios	*saved_settings;

	if (original_settings)
		saved_settings = original_settings;
	else if (saved_settings)
	{
		tcsetattr(STDIN_FILENO, TCSAFLUSH, saved_settings);
		free(saved_settings);
	}
}

struct termios	*ft_makeraw(void)
{
	struct termios	new_settings;
	struct termios	default_settings;
	struct termios	*ret;

	if (!isatty(STDIN_FILENO))
		ft_fatal("err: not a terminal\n");
	if (!(ret = (struct termios *)malloc(sizeof(struct termios *))))
		ft_fatal("err: out of memory\n");
	tcgetattr(STDIN_FILENO, &default_settings);
	reset_terminal_settings(&default_settings);
	tcgetattr(STDIN_FILENO, &new_settings);
	new_settings.c_iflag &= ~(ICRNL | IXON);
	new_settings.c_oflag &= ~(OPOST);
	new_settings.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	new_settings.c_cc[VMIN] = 0;
	new_settings.c_cc[VTIME] = 1;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &new_settings) == -1)
		ft_fatal("err: unable to enter raw mode\n");
	return (ret);
}

void			load_terminal(void)
{
	char	*termtype;
	char	*buff;
	int		status;

	termtype = (void *)0;
	if (!(buff = (char *)malloc(2048 * sizeof(char))))
		ft_fatal("err: out of memory\n");
	if (!(termtype = getenv("TERM")))
		ft_fatal("err: terminal type unavailable\n");
	if ((status = tgetent(buff, termtype)) <= 0)
		ft_fatal("err: unable to load terminal\n");
	ft_str_atexit(1, buff);
}
