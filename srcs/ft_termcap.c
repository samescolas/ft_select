/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:18:24 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/28 12:29:54 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"
#include "ft_terminfo.h"

int		ft_putc(int c)
{
	write(STDIN_FILENO, &c, 1);
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
