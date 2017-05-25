/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_window.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:49:21 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/25 09:00:03 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_types.h"
#include "ft_terminfo.h"

t_window	*ft_create_window(int num_args)
{
	t_window	*ret;

	if (!(ret = (t_window *)malloc(sizeof(t_window))))
		ft_fatal("err: out of memory\n\r");
	ret->term_width = get_term_width();
	ret->term_height = get_term_height();
	ret->border_top = 0;
	ret->border_left = 0;
	ret->num_cols = 1;
	ret->num_args = num_args;
	ret->h_padding = 0;
	ret->v_padding = 0;
	ret->box_width = 0;
	ret->box_height = 0;
	return (ret);
}
