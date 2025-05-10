/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gaeudes <gaeudes@made-f0Br6s11.clusters    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:21:16 by Gaeudes           #+#    #+#             */
/*   Updated: 2025/03/09 16:01:41 by Gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	update_flags_dc(t_dict *dc)
{
	if (dc->pars.b_read < 0)
		dc->flags &= ~F_VALID;
	if (dc->pars.b_read == 0 || !(dc->flags & F_VALID))
		dc->flags &= ~F_KEEP_READ;
}

void	read_one(t_dict *dc)
{
	dc->pars.b_read = read(dc->pars.fd, &dc->pars.r_char, 1);
	update_flags_dc(dc);
}

int	open_dict(t_dict *dc, char *file_name)
{
	dc->pars.fd = open(file_name, O_RDONLY);
	if (dc->pars.fd < 0)
	{
		dc->flags &= ~F_VALID;
		return (1);
	}
	return (0);
}

void	free_dict(t_dict *dc)
{
	int	i;

	free(dc->pars.buffer_cpy);
	i = -1;
	while (++i < 10)
		free(dc->n_0_9[i]);
	i = -1;
	while (++i < 10)
		free(dc->n_10_19[i]);
	i = -1;
	while (++i < 8)
		free(dc->n_20_90[i]);
	free(dc->n_100);
	i = -1;
	while (++i < 12)
		free(dc->n_p_1000[i]);
}

void	check_dict_full(t_dict *dc)
{
	int	i;
	int	err;

	err = 0;
	i = -1;
	while (++i < 10)
		err |= !dc->n_0_9[i];
	i = -1;
	while (++i < 10)
		err |= !dc->n_10_19[i];
	i = -1;
	while (++i < 8)
		err |= !dc->n_20_90[i];
	err |= !dc->n_100;
	i = -1;
	while (++i < 12)
		err |= !dc->n_p_1000[i];
	if (err)
		dc->flags &= ~F_VALID;
}
