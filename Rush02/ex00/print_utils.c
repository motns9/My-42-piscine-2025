/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gaeudes <gaeudes@made-f0Br6s11.clusters    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:53:03 by Gaeudes           #+#    #+#             */
/*   Updated: 2025/03/09 14:53:53 by Gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	write_space(int	*start, int *err)
{
	if (!*start && write(1, " ", 1) != 1)
		*err = 1;
	*start = 0;
}

void	write_word(char *word, int *err)
{
	int	i;

	i = 0;
	while (word[i])
		++i;
	if (write(1, word, i) != i)
		*err = 1;
}
