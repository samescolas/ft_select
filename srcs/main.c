/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 10:23:04 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/23 18:01:19 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "ft_atexit.h"
#include "ft_types.h"

#include "../libft/libft.h"

int		get_max_length(char **arr)
{
	int		max;
	int		len;
	int		i;

	i = 0;
	max = ft_strlen(arr[i]);
	while (arr[++i])
		if ((len = ft_strlen(arr[i])) > max)
			max = len;
	return (max);
}

int		main(int argc, char **argv)
{
	t_window	*term;

	if (argc > 1)
	{
		term = load_terminal();
		ft_putnbr(get_max_length(&argv[1]));
		write(1, "\n\r", 2);
		ft_atexit();
	}
	return (0);
}
