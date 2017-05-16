/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atexit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 11:38:18 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/16 12:05:08 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_select.h"

static void	resize_arr(char ***arr, int size, int buff_size)
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

void	ft_str_atexit(int loading, char *str_to_free)
{
	static char	**string_arr;
	static int	num_strings;
	int			buff_size;
	int			i;

	buff_size = 10;
	i = -1;
	if (num_strings == 0)
		if (!(string_arr = (char **)malloc(buff_size * sizeof(char *))))
			ft_fatal("err: out of memory\n");
	if (loading)
	{
		if (num_strings > 0 && num_strings % 10 == 0)
			resize_arr(&string_arr, num_strings, buff_size);
		string_arr[num_strings++] = str_to_free;
	}
	else
	{
		while (++i < num_strings)
			ft_strdel(&string_arr[i]);
		free(string_arr);
		string_arr = (void *)0;
	}
}

void	ft_atexit(void)
{
	ft_str_atexit(0, (void *)0);
	exit(0);
}
