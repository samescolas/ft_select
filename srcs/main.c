/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 10:23:04 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/25 15:46:12 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "ft_atexit.h"
#include "ft_types.h"

#include "ft_terminfo.h"
#include "dimensionalize.h"
#include "parametrize.h"
#include <stdio.h>
#include "../libft/libft.h"
#include "ft_termcap.h"

void	display_choice(t_choice choice, t_coord *pos);

void	print_term_contents(t_window term)
{
	printf("\ncolumns: %zu\targs: %zu\n\r",\
					term.num_cols, term.num_args);
	
	printf("border: %zu\n\n\rbox\n\r\twidth: %zu\theight: %zu\n\r",\
					term.border_top, term.box_width, term.box_height);
	
	printf("\npadding\n\r\tv: %zu\th: %zu\n\n\r",\
					term.v_padding, term.h_padding);
}

void	print_list(t_choice *list)
{
	t_choice	*tmp;
	int			to_do;

	tmp = list;
	to_do = 1;
	while (to_do || tmp != list)
	{
		to_do = 0;
//		printf("%s (%zu, %zu)\n\r", tmp->label, tmp->position->x, tmp->position->y);
		display_choice(*tmp, 0);
		tmp = tmp->next;
	}
}

int		main(int argc, char **argv)
{
	t_window	*term;
	t_choice	*list;

	if (argc > 1)
	{
		term = load_terminal(argc - 1);
		ft_clear_screen(*term);
		test_dimensions(argv, term);
		dimensionalize(term);
//		print_term_contents(*term);
//		printf("width: %zu\theight: %zu\n\r", term->term_width, term->term_height);
		list = parametrize_options(&argv[1], term);
		print_list(list);
		ft_atexit();
	}
	return (0);
}
