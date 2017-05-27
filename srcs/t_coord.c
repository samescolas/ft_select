/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_coord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:44:34 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/26 11:29:14 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "../libft/libft.h"

t_coord		*create_coord(size_t x, size_t y)
{
	t_coord		*ret;

	if (!(ret = (t_coord *)malloc(sizeof(t_coord))))
		ft_fatal("err: out of memory\n\r");
	ret->x = x;
	ret->y = y;
	return (ret);
}

void		uncoordinate(t_coord *coord)
{
	if (!coord)
		return ;
	free(coord);
	coord = (void *)0;
}
