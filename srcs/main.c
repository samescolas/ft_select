/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 10:23:04 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/23 17:24:03 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "ft_atexit.h"

#include "../libft/libft.h"

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		load_terminal();
		ft_atexit();
	}
	return (!argv[0]);
}
