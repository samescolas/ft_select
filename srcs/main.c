/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 10:23:04 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/16 12:21:02 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "ft_atexit.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>

void	load_terminal(void)
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

int		main(void)
{
	load_terminal();
	
	ft_atexit();
	//printf("tty: %s\n", ttyname(STDOUT_FILENO));
}
