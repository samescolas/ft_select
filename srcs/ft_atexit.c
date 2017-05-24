/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atexit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 11:38:18 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/23 17:33:53 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atexit.h"
#include "../libft/libft.h"

static void	resize_str_arr(char ***arr, int size, int buff_size)
{
	char	**ret;
	int		i;

	if (!(ret = (char **)malloc((size + buff_size) * sizeof(char *))))
		ft_fatal("err: out of memory\n");
	i = -1;
	while (++i < size)
		ret[size] = (*arr)[size];
	ret[size] = (void *)0;
	free(*arr);
	*arr = ret;
}

static void	resize_func_arr(void (***arr)(void), int size, int buff_size)
{
	void	(**ret)(void);
	int		i;

	if (!(ret = (void (**)(void))malloc((size + buff_size) * sizeof(void (*)(void)))))
		ft_fatal("err: out of memory\n");
	i = -1;
	while (++i < size)
		ret[size] = (*arr)[size];
	ret[size] = (void *)0;
	free(*arr);
	*arr = ret;
}

void		ft_str_atexit(int loading, char *str_to_free)
{
	static char	**string_arr;
	static int	num_strings;
	int			i;

	i = -1;
	if (!num_strings)
		if (!(string_arr = (char **)malloc(STRING_BUFFER * sizeof(char *))))
			ft_fatal("err: out of memory\n");
	if (loading)
	{
		write(1, "\r", 1);
		if (num_strings > 0 && num_strings % STRING_BUFFER == 0)
			resize_str_arr(&string_arr, num_strings, STRING_BUFFER);
		string_arr[num_strings++] = str_to_free;
	}
	else
	{
		while (++i < num_strings)
		{
			ft_bzero(string_arr[i], sizeof(string_arr[i]));
			free(string_arr[i]);
			string_arr[i] = (void *)0;
		}
		free(string_arr);
		string_arr = (void *)0;
	}
}

void		ft_func_atexit(int loading, void (*func_to_load)(void))
{
	static void	(**func_arr)(void);
	static int	num_funcs;
	int			i;

	i = -1;
	if (num_funcs == 0)
		if (!(func_arr = (void (**)(void))malloc(FUNCTION_BUFFER * sizeof(void (*)(void)))))
			ft_fatal("err: out of memory\n");
	if (loading)
	{
		if (num_funcs > 0 && num_funcs % FUNCTION_BUFFER == 0)
			resize_func_arr(&func_arr, num_funcs, FUNCTION_BUFFER);
		func_arr[num_funcs++] = func_to_load;
	}
	else
	{
		while (++i < num_funcs)
		{
			func_arr[i]();
			func_arr[i] = (void *)0;
		}
		free(func_arr);
		func_arr = (void *)0;
	}
}

void	ft_atexit(void)
{
	ft_str_atexit(0, (void *)0);
	ft_func_atexit(0, (void *)0);
	exit(0);
}
