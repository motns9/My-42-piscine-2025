/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:12:00 by msbita            #+#    #+#             */
/*   Updated: 2025/03/09 22:12:02 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	fix_and_cpy_value(t_dict *dc)
{
	int	i;

	i = 0;
	while (dc->pars.buffer_cpy[i])
		++i;
	--i;
	while (dc->pars.buffer_cpy[i] == ' ')
		dc->pars.buffer_cpy[i--] = 0;
	if (dc->pars.ptr_to_value)
	{
		if (*dc->pars.ptr_to_value)
		{
			dc->pars.ptr_to_value = 0;
			dc->flags &= ~F_KEEP_READ;
			dc->flags &= ~F_VALID;
			return ;
		}
		*(dc->pars.ptr_to_value) = dc->pars.buffer_cpy;
	}
	else
		free(dc->pars.buffer_cpy);
	dc->pars.buffer_cpy = 0;
	dc->pars.ptr_to_value = 0;
}

void	skip_before_value(t_dict *dc)
{
	while ((dc->flags & F_KEEP_READ) && dc->pars.r_char == ' ')
		read_one(dc);
	if ((dc->flags & F_KEEP_READ) && dc->pars.r_char == ':')
		read_one(dc);
	else
		dc->flags &= ~F_KEEP_READ;
	while ((dc->flags & F_KEEP_READ) && dc->pars.r_char == ' ')
		read_one(dc);
	dc->pars.buffer_cpy = malloc(sizeof(char));
	if (!dc->pars.buffer_cpy)
	{
		dc->flags = (dc->flags | F_MALLOC_ERROR) & ~F_KEEP_READ;
		return ;
	}
	dc->pars.len_buff = 0;
	dc->pars.buffer_cpy[0] = 0;
	while ((dc->flags & F_KEEP_READ) && is_printable(dc->pars.r_char)
		&& dc->pars.r_char != '\n')
	{
		++dc->pars.len_buff;
		realloc_cpy(dc);
		read_one(dc);
	}
	if ((dc->flags & F_KEEP_READ))
		fix_and_cpy_value(dc);
}

void	read_key(t_dict *dc)
{
	dc->pars.buffer_cpy = malloc(sizeof(char) * 1);
	if (!dc->pars.buffer_cpy)
	{
		dc->flags = (dc->flags | F_MALLOC_ERROR) & ~F_KEEP_READ;
		return ;
	}
	dc->pars.len_buff = 0;
	dc->pars.buffer_cpy[0] = 0;
	while ((dc->flags & F_KEEP_READ) && is_number(dc->pars.r_char)
		&& ++dc->pars.len_buff)
		(realloc_cpy(dc), read_one(dc));
	if ((dc->flags & F_KEEP_READ) && !dc->pars.len_buff && dc->pars.read_0)
	{
		dc->pars.read_0 = dc->pars.r_char;
		dc->pars.len_buff = 1;
		dc->pars.r_char = '0';
		dc->pars.r_char = (realloc_cpy(dc), dc->pars.read_0);
	}
	else if (!dc->pars.len_buff)
		dc->flags &= ~F_KEEP_READ;
	dc->pars.read_0 = 0;
	if (dc->flags & F_KEEP_READ)
		find_key_adrr_value(dc);
	if (dc->flags & F_KEEP_READ)
		skip_before_value(dc);
}

int	read_dict_line(t_dict *dc)
{
	dc->pars.read_minus = 0;
	while ((dc->flags & F_KEEP_READ) && dc->pars.r_char == '\n')
		read_one(dc);
	while ((dc->flags & F_KEEP_READ) && is_whitespace(dc->pars.r_char))
		read_one(dc);
	if ((dc->flags & F_KEEP_READ) && (dc->pars.r_char == '+'
			|| dc->pars.r_char == '-'))
	{
		if (dc->pars.r_char == '-')
			dc->pars.read_minus = 1;
		read_one(dc);
	}
	while ((dc->flags & F_KEEP_READ) && dc->pars.r_char == '0')
	{
		dc->pars.read_0 = 1;
		read_one(dc);
	}
	if (dc->flags & F_KEEP_READ)
		read_key(dc);
	if ((dc->flags & F_KEEP_READ) && dc->pars.r_char == '\n')
		read_one(dc);
	else
		dc->flags &= ~F_KEEP_READ;
	return (dc->flags & F_KEEP_READ);
}

void	parse_dict(t_dict *dc, char *file_name)
{
	dc->flags = F_KEEP_READ | F_VALID;
	if (open_dict(dc, file_name))
		return ;
	read_one(dc);
	while (read_dict_line(dc))
		;
	close(dc->pars.fd);
	check_dict_full(dc);
	if (!(dc->flags & F_VALID))
		free_dict(dc);
}
