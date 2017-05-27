/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:39:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/26 16:16:58 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_types.h"
#include "ft_display.h"

/*
static void		resize_buffer(char **line, unsigned int current_size)
{
	char	*tmp;

	tmp = ft_strnew(current_size + BUFF_SIZE);
	ft_strncpy(tmp, *line, current_size);
	ft_strdel(line);
	*line = tmp;
}

static void		key_printable(char c, char *line, unsigned int *chars_copied)
{
	char	bkspc[3];

	if (c == 127)
	{
		if (*chars_copied == 0)
			return ;
		bkspc[0] = 8;
		bkspc[1] = 127;
		bkspc[2] = 8;
		line[--(*chars_copied)] = '\0';
		write(1, bkspc, 3);
		return ;
	}
	if (*chars_copied == 0 && c == ';')
		return ;
	write(1, &c, 1);
	line[(*chars_copied)++] = c;
}
*/

void		handle_ctrl(char c, t_window *win, t_choice **list)
{
	int		ret;

	if ((ret = read(STDIN_FILENO, &c, 1)) > 0)
	{
		if (!c)
			ft_fatal("esc pressed\n\r");
		else if (c == 'A')
		{
			/* up */
			ret = -1;
			while (++ret < (int)win->num_cols)
				*list = (*list)->prev;
			print_list(*list);
		}
		else if (c == 'B')
		{
			/* down */
			ret = -1;
			while (++ret < (int)win->num_cols)
				*list = (*list)->next;
			print_list(*list);
		}
		else if (c == 'C')
		{
			/* right */
			*list = (*list)->next;
			print_list(*list);
		}
		else if (c == 'D')
		{
			/* left */
			*list = (*list)->prev;
			print_list(*list);
		}
	}
}

void		handle_keypress(char c, t_window *win, t_choice **list)
{
	if (c == ' ')
	{
		(*list)->selected = !((*list)->selected);
		print_list(*list);
	}
	else if (c == 'h' || c == 'i' || c == 'j' || c == 'k')
	{
		ft_putchar_fd(c, STDIN_FILENO);
		handle_ctrl(c, win, list);
	}
	else if (c == 127)
	{
		ft_fatal("backspace pressed!\n\r");
	}
}


/*
void			read_line(t_window *win, t_choice **list)
{
	char			buf;
	int				ret;
	unsigned int	chars_copied;

	chars_copied = 0;
	if (!win || !list)
		return ;
	while (1 (ret = read(STDIN_FILENO, &buf, 1)) > 0 && buf != '\n')
	{
		if ((ret = read(STDIN_FILENO, &buf, 1)) > 0 && buf == 27)
		{
			if ((ret = read(STDIN_FILENO, &buf, 1)) > 0 && buf == '[')
				handle_ctrl(buf, win, list);
		}
	}
}
*/
