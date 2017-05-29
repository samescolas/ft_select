/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:33:19 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/29 08:56:55 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_H
# define FT_DISPLAY_H

typedef struct s_window	t_window;
typedef struct s_choice	t_choice;

void		launch_menu(int num_choices, char **choices);
void		redisplay(\
				t_choice ***list, t_window *win, char **args, int preserve);
void		display_choice(t_choice choice, int active);
void		print_list(t_choice *list);

void		ft_keypress(char c, t_window *win, t_choice ***list, char **args);

t_choice	**reassign_coords(t_choice ***list, char **choices, t_window *win);
t_choice	**parametrize_choices(char **choices, t_window *win);

#endif
