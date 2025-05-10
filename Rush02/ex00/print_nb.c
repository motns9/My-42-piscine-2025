/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:12:31 by msbita            #+#    #+#             */
/*   Updated: 2025/03/09 22:12:33 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_block_s1(char *block, int *start, t_dict dc, int *err)
{
	write_space(start, err);
	write_word(dc.n_0_9[block[0] - '0'], err);
}

void	print_block_s2(char *block, int *start, t_dict dc, int *err)
{
	if (block[0] == '0' && block[1] == '0')
		return ;
	write_space(start, err);
	if (block[0] == '0')
		write_word(dc.n_0_9[block[1] - '0'], err);
	else if (block[0] == '1')
		write_word(dc.n_10_19[block[1] - '0'], err);
	else
	{
		write_word(dc.n_20_90[block[0] - '0' - 2], err);
		if (block[1] != '0')
		{
			write_space(start, err);
			write_word(dc.n_0_9[block[1] - '0'], err);
		}
	}
}

void	print_block_s3(char *block, int *start, t_dict dc, int *err)
{
	if (block[0] != '0')
	{
		write_space(start, err);
		write_word(dc.n_0_9[block[0] - '0'], err);
		write_space(start, err);
		write_word(dc.n_100, err);
	}
	print_block_s2(block + 1, start, dc, err);
}

void	print_block(char *block, int len, int *start, t_r02 *r02)
{
	if (len == 0)
		return ;
	if (len == 1)
		print_block_s1(block, start, r02->dict, &(r02->error_write));
	else if (len == 2)
		print_block_s2(block, start, r02->dict, &(r02->error_write));
	else
		print_block_s3(block, start, r02->dict, &(r02->error_write));
	if ((len == 3 && (block[0] != '0' || block[1] != '0' || block[2] != '0'))
		|| len < 3)
	{
		len = (r02->nb_len - r02->i_print - 1) / BLOCK_SIZE - 1;
		if (len >= 0)
		{
			write_space(start, &(r02->error_write));
			write_word(r02->dict.n_p_1000[len], &(r02->error_write));
		}
	}
}

void	print_nb(t_r02 *r02)
{
	int	start;

	start = 1;
	print_block(r02->nb_to_trad, r02->off_set, &start, r02);
	r02->i_print = r02->off_set;
	while (r02->i_print < r02->nb_len)
	{
		print_block(r02->nb_to_trad + r02->i_print, BLOCK_SIZE, &start, r02);
		r02->i_print += BLOCK_SIZE;
	}
	write_word("\n", &(r02->error_write));
}
