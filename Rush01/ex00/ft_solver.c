/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mireyes- <mireyes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:30:54 by mireyes-          #+#    #+#             */
/*   Updated: 2025/03/02 17:57:49 by mireyes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	solve(int **grid, int values, int pos, int n)
{
	int	size;

	if (pos == n * n)
		return (1);
	size = 1;
	while (size <= n)
	{
		if (check_cross(grid, pos, size, n))
		{
			grid[pos / n][pos % n] = size;
			if (check_safe(grid, pos, values, n))
			{
				if (solve(grid, values, pos + 1, n))
					return (1);
			}
			else
				grid[pos / n][pos % n] = 0;
		}
		size++;
	}
	return (0);
}
//Use backtracking to place the boxes while satisfying the constraints:
//Each row and column must have unique values (1 through n).
//The visibility values must match the input criteria.
