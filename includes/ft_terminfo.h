/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminfo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:56:32 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/24 11:48:44 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMINFO_H
# define FT_TERMINFO_H

typedef struct s_window	t_window;

int		get_term_width(void);
int		get_term_height(void);
int		check_term_width(t_window win);
int		check_term_height(t_window win);

#endif
