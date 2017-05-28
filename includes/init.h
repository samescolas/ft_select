/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:18:46 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/27 17:56:55 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <termios.h>
# include <curses.h>
# include <term.h>

typedef struct s_window t_window;

void			reset_terminal(void);
t_window		*load_terminal(int num_args, char **args);
void			dimensionalize(char **args, t_window *win, int num_cols);

#endif
