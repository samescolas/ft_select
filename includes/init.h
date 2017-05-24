/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:18:46 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/24 10:38:12 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <termios.h>
# include <curses.h>
# include <term.h>

typedef struct s_window t_window;

void			reset_terminal(void);
t_window		*load_terminal(int num_args);

#endif
