/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:18:46 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/23 15:29:09 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <termios.h>
# include <curses.h>
# include <term.h>

void			ft_makeraw(void);
void			reset_terminal_settings(struct termios *original_settings);
void			load_terminal(void);

#endif
