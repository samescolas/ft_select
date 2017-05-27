/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 10:23:04 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/26 14:52:46 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "ft_atexit.h"
#include "ft_types.h"
#include "ft_termcap.h"
#include "ft_display.h"
#include "dimensionalize.h"
#include "parametrize.h"

int		main(int argc, char **argv)
{
	t_window	*term;
	t_choice	*list;

	term = load_terminal(argc - 1);
	ft_clear_screen(*term);
	dimensionalize(argv, term);
	list = parametrize_options(&argv[1], term);
	launch_menu(&list, term, &argv[1]);
	ft_atexit();
	return (0);
}
