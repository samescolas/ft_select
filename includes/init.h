/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:18:46 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/23 16:55:07 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <termios.h>
# include <curses.h>
# include <term.h>

void			reset_terminal(void);
void			load_terminal(void);

#endif
