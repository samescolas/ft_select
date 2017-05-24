/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 10:23:04 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/24 14:38:19 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "ft_atexit.h"
#include "ft_types.h"

#include "ft_terminfo.h"
#include "dimensionalize.h"
#include <stdio.h>
#include "../libft/libft.h"

int		main(int argc, char **argv)
{
	t_window	*term;

	if (argc > 1)
	{
		term = load_terminal(argc - 1);
		test_dimensions(argv, term);
		ft_atexit();
	}
	return (0);
}
