/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:33:19 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/27 18:03:14 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_H
#define FT_DISPLAY_H

void		display_choice(t_choice choice, int active);
void		print_list(t_choice *list);
void		launch_menu(t_choice **list, t_window *win, char **args);
void		read_line(t_window *win, t_choice **list);
void		redisplay(t_choice ***list, t_window *win, char **args, int preserve);

#endif
