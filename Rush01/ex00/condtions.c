/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condtions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mireyes- <mireyes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:06:53 by mireyes-          #+#    #+#             */
/*   Updated: 2025/03/02 18:07:17 by mireyes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_row(int **grid, int pos, int size, int n)
{
	int	i;
	int	row;

	i = 0;
	row = pos / n;
	while (i < n)
	{
		if (grid[row][i] == size)
			return (0);
		i++;
	}
	return (1);
}

int	check_column(int **grid, int pos, int size, int n)
{
	int	i;
	int	column;

	i = 0;
	column = pos % n;
	while (i < n)
	{
		if (grid[i][column] == size)
			return (0);
		i++;
	}
	return (1);
}

int	check_cross(int **grid, int pos, int size, int n)
{
	if (check_row(grid, pos, size, n) != 1)
		return (0);
	if (check_column(grid, pos, size, n) != 1)
		return (0);
	else
		return (1);
}
