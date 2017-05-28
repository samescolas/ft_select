/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:18:24 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/27 18:22:50 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"
#include "ft_types.h"
#include "ft_select.h"
#include "ft_terminfo.h"
#include "../libft/libft.h"

int		ft_putc(int c)
{
//	static int	fd;

//	if ((!fd && ((fd = open(ttyname(STDIN_FILENO), O_WRONLY | O_APPEND)) > 0))
		//|| fd)
		write(0, &c, 1);
	return (0);
}

void	ft_clear_screen(void)
{
	tputs(CL, get_term_height(), ft_putc);
}

void	ft_hide_cursor(void)
{
	tputs(VI, 1, ft_putc);
}

void	ft_show_cursor(void)
{
	tputs(VE, 1, ft_putc);
}
