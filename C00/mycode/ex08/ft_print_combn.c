/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:24:01 by msbita            #+#    #+#             */
/*   Updated: 2025/02/21 09:43:34 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	if (tab[0] != (10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_generate(int *tab, int n, int index, int start)
{
	int	i;

	if (index == n)
	{
		ft_print_number(tab, n);
		return ;
	}	
	i = start;
	while (i <= 9)
	{
		tab[index] = i;
		ft_generate(tab, n, index + 1, i + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	tab[10];

	ft_generate(tab, n, 0, 0);
}
