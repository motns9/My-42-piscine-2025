/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gaeudes <gaeudes@made-f0Br6s11.clusters    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:19:19 by Gaeudes           #+#    #+#             */
/*   Updated: 2025/03/09 12:19:52 by Gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_whitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s2;
		++s1;
	}
	return (*s1 - *s2);
}

void	realloc_cpy(t_dict *dc)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (dc->pars.len_buff + 1));
	if (!res)
	{
		dc->flags = (dc->flags | F_MALLOC_ERROR) & ~F_KEEP_READ;
		return ;
	}
	i = -1;
	while (dc->pars.buffer_cpy[++i])
		res[i] = dc->pars.buffer_cpy[i];
	res[i] = dc->pars.r_char;
	res[i + 1] = 0;
	free(dc->pars.buffer_cpy);
	dc->pars.buffer_cpy = res;
}
