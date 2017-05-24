/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 10:49:26 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/24 09:51:26 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

extern char		PC;
extern char		*UP;
extern char		*BC;
extern unsigned	ospeed;

int		tgetent(char *bp, const char *name);
int		tgetflag(char *id);
int		tgetnum(char *id);
char	*tgetstr(char *id, char **area);
char	*tgoto(const char *cap, int col, int row);
int		tputs(const char *str, int affcnt, int (*putc)(int));

#endif
