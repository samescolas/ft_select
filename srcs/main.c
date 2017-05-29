/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 10:23:04 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/29 10:56:56 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "ft_atexit.h"
#include "ft_types.h"
#include "ft_display.h"
#include "../libft/libft.h"
#include "ft_signal.h"

int		main(int argc, char **argv)
{
	save_argv(1, argv);
	update_signals(1);
	launch_menu(argc - 1, &argv[1]);
	ft_atexit();
	return (0);
}
