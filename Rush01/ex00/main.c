/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mireyes- <mireyes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:09:26 by mireyes-          #+#    #+#             */
/*   Updated: 2025/03/02 18:11:21 by mireyes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	count_numbers(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str >= '1' && *str <= '4')
			count++;
		else if (*str != ' ')
			return (-1);
		str++;
	}
	return (count);
}

int	*parse_input(char *str, int count)
{
	int	*values;
	int	i;
	int	j;

	i = 0;
	j = 0;
	values = (int *)malloc(count * sizeof(int));
	if (!values)
		return (NULL);
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			values[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (values);
}

int	main(int argc, char **argv)
{
	int	*values;
	int	count;
	int	**grid;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	grid = create_grid(4);
	count = count_numbers(argv[1]) != 16;
	values = parse_input(argv[1], count);
	if (!values || count_numbers(argv[1]) != 16)
	{
		ft_putstr("Error\n");
		free(values);
		return (1);
	}
	print_grid(grid);
	free(values);
	free_grid(grid);
}
