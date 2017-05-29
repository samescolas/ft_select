/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminfo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:56:32 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/29 10:33:57 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMINFO_H
# define FT_TERMINFO_H

# include <sys/ioctl.h>
# include <unistd.h>

typedef struct s_window	t_window;

int		tgetent(char *bp, const char *name);
int		tgetnum(char *id);
char	*tgetstr(char *id, char **area);
char	*tgoto(const char *cap, int col, int row);
int		tputs(const char *str, int affcnt, int (*putc)(int));

size_t	get_term_width(void);
size_t	get_term_height(void);
size_t	get_content_width(t_window win);
size_t	get_content_height(t_window win);
size_t	check_term_width(t_window win);
size_t	check_term_height(t_window win);
int		screen_size_changed(t_window *win);
void	wait_for_larger_window(char **choices, t_window *win);

#endif
