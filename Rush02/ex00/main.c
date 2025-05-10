/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gaeudes <gaeudes@made-f0Br6s11.clusters    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:37:53 by Gaeudes           #+#    #+#             */
/*   Updated: 2025/03/09 17:57:09 by Gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	fix_number(t_r02 *r02)
{
	int	i;

	i = -1;
	while (r02->nb_to_trad[++i])
		if (!is_number(r02->nb_to_trad[i]))
			r02->valid = 0;
	while (r02->nb_to_trad[0] == '0' && r02->nb_to_trad[1])
		++r02->nb_to_trad;
	i = 0;
	while (r02->nb_to_trad[i])
		++i;
	if (i > MAX_LEN_NB)
	{
		free_dict(&(r02->dict));
		r02->dict.flags &= ~F_VALID;
	}
	if (!i)
		r02->valid = 0;
	r02->nb_len = i;
	r02->off_set = i % BLOCK_SIZE;
}

void	rest_init(t_r02 *r02)
{
	r02->i_print = 0;
	r02->valid = 1;
	parse_dict(&r02->dict, r02->dict_file);
	fix_number(r02);
	if (r02->valid && r02->dict.flags & F_VALID)
		print_nb(r02);
	if (r02->dict.flags & F_VALID)
		free_dict(&(r02->dict));
}

void	init_ac_2(t_r02 *r02, char **av)
{
	r02->dict_file = "numbers.dict";
	r02->nb_to_trad = av[1];
	rest_init(r02);
}

void	init_ac_3(t_r02 *r02, char **av)
{
	r02->dict_file = av[1];
	r02->nb_to_trad = av[2];
	rest_init(r02);
}

int	main(int ac, char **av)
{
	static t_r02	r02 = {0};

	if (ac == 2)
		init_ac_2(&r02, av);
	else if (ac == 3)
		init_ac_3(&r02, av);
	else
	{
		write_word(ERR_NO_ARG, &r02.error_write);
		return (1);
	}
	if (!(r02.dict.flags & F_VALID))
		write_word(ERR_DICT, &r02.error_write);
	else if (!(r02.valid))
		write_word(ERR_NO_ARG, &r02.error_write);
	if (r02.error_write)
		write(2, "Write Error\n", 12);
	if (r02.dict.flags & F_MALLOC_ERROR)
		write(2, "Malloc Error\n", 13);
	if (!(r02.dict.flags & F_VALID) || !(r02.valid) || r02.error_write
		|| r02.dict.flags & F_MALLOC_ERROR)
		return (1);
	return (0);
}
