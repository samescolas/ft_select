/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:46:26 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/24 10:35:20 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

typedef struct	s_coord
{
	size_t		x;
	size_t		y;
}				t_coord;

typedef struct	s_window
{
	size_t	term_width;
	size_t	term_height;
	size_t	border_top;
	size_t	box_width;
	size_t	box_height;
	size_t	h_padding;
	size_t	v_padding;
	size_t	num_cols;
	size_t	num_args;
	
}				t_window;

t_window	*ft_create_window(int num_args);

#endif
