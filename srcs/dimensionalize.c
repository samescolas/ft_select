/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensionalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:53:46 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/24 15:14:37 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_types.h"
#include "ft_terminfo.h"

static int	get_max_length(char **arr)
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

void		test_dimensions(char **arg_list, t_window *win)
{
	if ((win->box_width = get_max_length(arg_list)) > win->term_width)
	{
		win->box_height = ft_ceil(win->box_width, win->term_width);
		if (win->box_height * win->num_args > win->term_height)
			ft_fatal("err: terminal window too small\n\r");
	}
	else
	{
		win->box_height = 1;
		while (check_term_width(*win) && !check_term_height(*win))
		{
			ft_putstr("increasing num of cols...\n\r");
			++(win->num_cols);
		}
		if (!check_term_width(*win) || !check_term_height(*win))
			ft_fatal("err: terminal window too small\n\r");
	}
}

void		dimensionalize(t_window *win)
{

}
