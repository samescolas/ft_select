/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 10:49:26 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/27 18:24:11 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* THINGS THAT NEED TO BE FIXED */
//	1	Ctrl-C Handler
//	2	Ctrl-Z Handler ? (properly return from fg)
//	3	Program is broken when passed a single argument
//	4	Check for memory leaks -- valgrind sees one
//	5	Double-check that I haven't broken resizing
//	6	Empty environment??
//	7	Refactor and fix the header sitution

#ifndef FT_SELECT_H
# define FT_SELECT_H

# define DEF "\x1B[0m"

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
