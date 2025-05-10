/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grille.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:31:59 by msbita            #+#    #+#             */
/*   Updated: 2025/03/02 17:58:36 by mireyes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	**create_grid(int n)
{
	int	**grille;
	int	ligne;

	grille = (int **)malloc(n * sizeof(int *));
	ligne = 0;
	while (ligne < n)
	{
		grille[ligne] = (int *)malloc(n * sizeof(int));
		ligne++;
	}
	return (grille);
}

void	free_grid(int **grille)
{
	int	ligne;

	ligne = 0;
	while (ligne < 4)
	{
		free(grille[ligne]);
		ligne++;
	}
	free(grille);
}

void	init_grid(int **grille)
{
	int	ligne;
	int	colonne;

	ligne = 0;
	while (ligne < 4)
	{
		colonne = 0;
		while (colonne < 4)
		{
			grille[ligne][colonne] = 0;
			colonne++;
		}
		ligne++;
	}
}

void	print_grid(int **grille)
{
	int		ligne;
	int		colonne;
	char	c;

	ligne = 0;
	while (ligne < 4)
	{
		colonne = 0;
		while (colonne < 4)
		{
			c = grille[ligne][colonne] + '0';
			ft_putchar(c);
			if (colonne < 3)
				ft_putchar(' ');
			colonne++;
		}
		ft_putchar('\n');
		ligne++;
	}
}
