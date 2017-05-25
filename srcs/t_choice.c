/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_choice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:45:33 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/25 09:28:26 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "../libft/libft.h"

t_choice	*create_choice(char *label, t_coord *position)
{
	t_choice	*ret;

	if (!(ret = (t_choice *)malloc(sizeof(t_choice))))
		ft_fatal("err: out of memory\n\r");
	ret->label = label;
	ret->len = ft_strlen(label);
	ret->position = create_coord(position->x, position->y);
	ret->selected = 0;
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

void		choice_add(t_choice **list, t_choice *item)
{
	if (!list || !*list)
	{
		*list = item;
		(*list)->next = *list;
		(*list)->prev = *list;
	}
	else
	{
		item->prev = (*list)->prev;
		item->next = (*list);
		(*list)->prev->next = item;
		(*list)->prev = item;
	}
}
