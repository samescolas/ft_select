/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 09:43:54 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/27 17:46:19 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "ft_termcap.h"
#include "ft_select.h"
#include "../libft/libft.h"

void	selected_mode(char *option, char *color)
{
	tputs(MR, 1, ft_putc);
	if (color)
		tputs(color, 1, ft_putc);
	tputs(option, 1, ft_putc);
	if (color)
		tputs(DEF, 1, ft_putc);
	tputs(ME, 1, ft_putc);
}

void	active_mode(char *option, char *color)
{
	tputs(US, 1, ft_putc);
	if (color)
		tputs(color, 1, ft_putc);
	tputs(option, 1, ft_putc);
	if (color)
		tputs(DEF,1, ft_putc);
	tputs(UE, 1, ft_putc);
}

void	active_and_selected_mode(char *option, char *color)
{
	tputs(SO, 1, ft_putc);
	tputs(US, 1, ft_putc);
	if (color)
		tputs(color, 1, ft_putc);
	tputs(option, 1, ft_putc);
	if (color)
		tputs(DEF, 1, ft_putc);
	tputs(UE, 1, ft_putc);
	tputs(SE, 1, ft_putc);
}

void	standout_mode(char *option, char *color)
{
	tputs(SO, 1, ft_putc);
	if (color)
		tputs(color, 1, ft_putc);
	tputs(option, 1, ft_putc);
	if (color)
		tputs(DEF, 1, ft_putc);
	tputs(SE, 1, ft_putc);
}

void	display_choice(t_choice choice, int active)
{
	tputs(tgoto(CM, choice.position->x, choice.position->y), 1, ft_putc);
	if (active && choice.selected)
		active_and_selected_mode(choice.label, "\x1B[38;5;99m");
	else if (active)
		active_mode(choice.label, "\x1B[38;5;97m");
	else if (choice.selected)
		selected_mode(choice.label, "\x1B[38;5;90m");
	else
		tputs(choice.label, 1, ft_putc);
	ft_hide_cursor();
}
