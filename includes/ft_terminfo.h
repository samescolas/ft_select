/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminfo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:56:32 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/24 15:59:47 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMINFO_H
# define FT_TERMINFO_H

typedef struct s_window	t_window;

size_t	get_term_width(void);
size_t	get_term_height(void);
size_t	get_content_width(t_window win);
size_t	get_content_height(t_window win);
size_t	check_term_width(t_window win);
size_t	check_term_height(t_window win);

#endif
