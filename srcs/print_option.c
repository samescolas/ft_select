/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 09:43:54 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/26 11:23:19 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "ft_termcap.h"
#include "ft_select.h"
#include "../libft/libft.h"

void	selected_mode(char *option)
{
	tputs(MR, 1, ft_putchar);
	tputs(option, 1, ft_putchar);
	tputs(ME, 1, ft_putchar);
}

void	active_mode(char *option)
{
	tputs(US, 1, ft_putchar);
	tputs(option, 1, ft_putchar);
	tputs(UE, 1, ft_putchar);
}

void	active_and_selected_mode(char *option)
{
	tputs(SO, 1, ft_putchar);
	tputs(US, 1, ft_putchar);
	tputs(option, 1, ft_putchar);
	tputs(UE, 1, ft_putchar);
	tputs(SE, 1, ft_putchar);
}

void	standout_mode(char *option)
{
	tputs(SO, 1, ft_putchar);
	tputs(option, 1, ft_putchar);
	tputs(SE, 1, ft_putchar);
}

void	display_choice(t_choice choice, int active)
{
	void	(*print_mode)(char *);

	print_mode = (void *)0;
	if (active && choice.selected)
		print_mode = &active_and_selected_mode;
	else if (active)
		print_mode = &active_mode;
	else if (choice.selected)
		print_mode = &selected_mode;
	ft_print_loc(choice.label, choice.position, print_mode);
}
