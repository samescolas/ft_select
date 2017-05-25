/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:46:26 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/25 09:28:09 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# include <stdlib.h>

typedef struct s_choice	t_choice;

typedef struct	s_window
{
	size_t	term_width;
	size_t	term_height;
	size_t	border_top;
	size_t	border_left;
	size_t	box_width;
	size_t	box_height;
	size_t	h_padding;
	size_t	v_padding;
	size_t	num_cols;
	size_t	num_args;
	
}				t_window;

typedef struct	s_coord
{
	size_t		x;
	size_t		y;
}				t_coord;

typedef struct	s_choice
{
	char		*label;
	size_t		len;
	t_coord		*position;
	size_t		selected;
	t_choice	*next;
	t_choice	*prev;
}				t_choice;

t_window	*ft_create_window(int num_args);
t_choice	*create_choice(char *label, t_coord *position);
t_coord		*create_coord(size_t x, size_t y);
void		choice_add(t_choice **list, t_choice *item);

#endif
