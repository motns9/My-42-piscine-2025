/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:07:12 by msbita            #+#    #+#             */
/*   Updated: 2025/03/12 15:10:25 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*array;
	int	size;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (-1);
	i = 0;
	while (i < size)
	{
		array[i] = min + i;
		i++;
	}
	*range = array;
	return (size);
}
/*
int	main(void)
{
	int	*range;
	int	size;
	int	i;

	size = ft_ultimate_range(&range, 5, 10);
	printf("Size: %d\n", size);
	if (range)
	{
		for (i = 0; i < size; i++)
			printf("%d ", range[i]);
		printf("\n");
		free(range);
	}
	return (0);
}
*/
