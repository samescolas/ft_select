/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 09:43:54 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/28 15:41:38 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "ft_termcap.h"
#include "ft_terminfo.h"
#include "../libft/libft.h"

static void	ft_putterm(char *str)
{
	tputs(str, 1, ft_putc);
}

static char	*create_color(char *code)
{
	char	*color;

	color = ft_strnew(10);
	ft_strcat(color, "\x1B[38;5;");
	ft_strcat(color, code);
	ft_strcat(color, "m\0");
	return (color);
}

static char	*get_color(char *choice)
{
	char	*ext;

	if ((ext = ft_strrchr(choice, '.')))
	{
		if (ft_strequ(ext, ".c"))
			return (create_color("90"));
		else if (ft_strequ(ext, ".h"))
			return (create_color("97"));
		else if (ft_strequ(ext, ".o"))
			return (create_color("29"));
		else if (ft_strequ(ext, ".a"))
			return (create_color("33"));
		else
			return (create_color("22"));
	}
	else
		return (create_color("37"));
}

void		display_choice(t_choice choice, int active)
{
	char	*color;

	ft_putterm(tgoto(CM, choice.position->x, choice.position->y));
	if (active)
		ft_putterm(US);
	if (choice.selected)
		ft_putterm(MR);
	ft_putterm((color = get_color(choice.label)));
	ft_putterm(choice.label);
	ft_putterm("\x1B[0m");
	if (active)
		ft_putterm(UE);
	if (choice.selected)
		ft_putterm(ME);
	ft_strdel(&color);
}
