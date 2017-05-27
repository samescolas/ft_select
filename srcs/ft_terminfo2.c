/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminfo2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:22:48 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/26 15:29:22 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_terminfo.h"
#include "ft_types.h"
#include "../libft/libft.h"

static size_t	get_winsize(char dim)
{
	struct winsize	screen_size;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &screen_size) == -1)
		ft_fatal("err: unable to determine terminal dimensions\n\r");
	if (dim == 'c' || dim == 'w')
		return ((size_t)screen_size.ws_col);
	return ((size_t)screen_size.ws_row);
}

size_t			get_term_width(void)
{
	return (get_winsize('w'));
}

size_t			get_term_height(void)
{
	return (get_winsize('h'));
}

int				screen_size_changed(t_window *term)
{
	return (term->term_width != get_term_width() ||\
				term->term_height != get_term_height());
}
