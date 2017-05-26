/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 09:43:54 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/25 11:43:29 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "ft_termcap.h"


void	display_choice(t_choice choice, int active)
{
	ft_print_loc(choice.label, choice.position);
	if (active)
		return ;
}
