/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:18:24 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/25 11:47:08 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"
#include "ft_types.h"
#include "ft_select.h"
#include "../libft/libft.h"

void	ft_print_loc(char *str, t_coord *loc)
{
	tputs(tgoto(CM, (int)loc->x, (int)loc->y), 1, ft_putchar);
	write(1, str, ft_strlen(str));
}

void	ft_clear_screen(t_window win)
{
	tputs(CL, win.term_height, ft_putchar);
}
