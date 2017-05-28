/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 10:23:04 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/27 18:16:54 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "ft_atexit.h"
#include "ft_types.h"
#include "ft_termcap.h"
#include "ft_display.h"
#include "parametrize.h"
#include "../libft/libft.h"
#include <unistd.h>

void	start_menu(int argc, char **argv)
{
	t_window	*win;
	t_choice	*list;
	pid_t		child_pid;
	int			status;

	if ((child_pid = fork()) < 0)
		ft_fatal("err: unable to start process\n");
	if (child_pid == 0)
	{
		win = load_terminal(argc, &argv[1]);
		list = parametrize_options(argv, win);
		launch_menu(&list, win, argv);
	}
	else
		waitpid(child_pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status))
		ft_fatal("err: something went wrong\n\r");
	ft_atexit();
}

int		main(int argc, char **argv)
{
//	t_window	*term;
//	t_choice	*list;
	start_menu(argc - 1, &argv[1]);

/*	
	term = load_terminal(argc - 1);
	ft_clear_screen();
	dimensionalize(argv, term, 0);
	list = parametrize_options(&argv[1], term);
	launch_menu(&list, term, &argv[1]);
	
	write(1, "here!!!!\n", 10);
*/
	ft_atexit();
	return (0);
}
