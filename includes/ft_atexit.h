/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atexit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 11:48:25 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/24 16:57:04 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ATEXIT_H
# define FT_ATEXIT_H

# define STRING_BUFFER 5
# define FUNCTION_BUFFER 5

typedef void	(*t_void_func_ptr)(void);

void	ft_atexit(void);
void	ft_str_atexit(int loading, char *str_to_free);
void	ft_func_atexit(int loading, void (*f)(void));

#endif
