/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 15:25:20 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/29 10:59:17 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signal.h"
#include "ft_termcap.h"
#include "init.h"
#include "../libft/libft.h"
#include "ft_display.h"

static void	sig_handler_suspend(int sig)
{
	if (sig == SIGTSTP || sig == SIGSTOP)
	{
		ft_putendl("inside sign handler\r");
		ft_clear_screen();
		ft_show_cursor();
		reset_terminal();
		kill(STDIN_FILENO, SIGSTOP);
	}
	else if (sig == SIGCONT)
		launch_menu(-1742, save_argv(0, (void *)0));
	else
		ft_fatal("err: unrecognized signal\n\r");
}

static void	*set_signal(int sig)
{
	struct sigaction	suspend_handler;
	struct sigaction	old_handler;

	suspend_handler.sa_handler = sig_handler_suspend;
	sigemptyset(&suspend_handler.sa_mask);
	suspend_handler.sa_flags = SA_NODEFER;
	sigaction(sig, (void *)0, &old_handler);
	sigaction(sig, &suspend_handler, (void *)0);
	return (old_handler.sa_handler);
}

void		update_signals(int loading)
{
	static void	*prev_signal_stop;
	static void	*prev_signal_susp;
	static void	*prev_signal_cont;

	if (loading)
	{
		prev_signal_stop = signal(SIGINT, SIG_IGN);
		prev_signal_susp = set_signal(SIGTSTP);
		prev_signal_cont = set_signal(SIGCONT);
	}
	else
	{
		signal(SIGINT, prev_signal_stop);
		signal(SIGTSTP, prev_signal_susp);
		signal(SIGCONT, prev_signal_cont);
	}
}

char		**save_argv(int load, char **args)
{
	static char	**argv_saved;

	if (load)
		argv_saved = args;
	else
		return (argv_saved);
	return ((void *)0);
}

void		reset_signals(void)
{
	update_signals(0);
}
