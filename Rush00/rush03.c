/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:10:56 by msbita            #+#    #+#             */
/*   Updated: 2025/02/23 17:52:14 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_first_or_last_line(int x)
{
	int	colonne;

	colonne = 0;
	while (colonne < x)
	{
		if (colonne == 0)
			ft_putchar('A');
		else if (colonne == x - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
		colonne++;
	}
	ft_putchar('\n');
}

void	print_middle_line(int x)
{
	int	colonne;

	colonne = 0;
	while (colonne < x)
	{
		if (colonne == 0 || colonne == x - 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
		colonne++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	ligne;

	if (x <= 0 || y <= 0)
	{
		write(1, "x et/ou y est invalide(s)\n", 26);
		return ;
	}
	print_first_or_last_line(x);
	ligne = 1;
	while (ligne < y - 1)
	{
		print_middle_line(x);
		ligne++;
	}
	if (y > 1)
		print_first_or_last_line(x);
}
