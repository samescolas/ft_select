/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 10:03:22 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/24 10:10:15 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMCAP_H
# define FT_TERMCAP_H

# define CL tgetstr("cl", (void *)0);
# define CM tgetstr("cm", (void *)0);
# define SO tgetstr("so", (void *)0);
# define SE tgetstr("se", (void *)0);
# define MR tgetstr("mr", (void *)0);
# define ME tgetstr("me", (void *)0);
# define MB tgetstr("mb", (void *)0);
# define MD tgetstr("md", (void *)0);
# define US tgetstr("us", (void *)0);
# define UE tgetstr("ue", (void *)0);
# define VI tgetstr("vi", (void *)0);
# define VE tgetstr("ve", (void *)0);
# define VS tgetstr("vs", (void *)0);
# define AS tgetstr("as", (void *)0);
# define AE tgetstr("ae", (void *)0);
# define BL tgetstr("bl", (void *)0);
# define VB tgetstr("vb", (void *)0);

#endif
