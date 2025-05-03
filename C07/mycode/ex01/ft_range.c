/* ************************************************************************** */
/*                                      */
/*                            :::     ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                          +:+ +:+       +:+    */
/*   By: msbita <msbita@student.42.fr>        +#+  +:+       +#+    */
/*                        +#+#+#+#+#+   +#+     */
/*   Created: 2025/03/10 21:00:06 by msbita   #+#  #+#          */
/*   Updated: 2025/03/11 14:39:06 by msbita           ###   ########.fr       */
/*                                      */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tableau;
	int	size;

	size = max - min;
	i = 0;
	if (min >= max)
	{
		return (NULL);
	}
	tableau = (int *)malloc((size) * sizeof(int));
	if (tableau == NULL)
		return (NULL);
	while (i < size)
	{
		tableau[i] = min;
		min++;
		i++;
	}
	return (tableau);
}
/*
int main(void)
{
	int start = 0, end = 10;
	int *res =ft_range(start, end);
	for(int i = 0; i < end - start; ++i)
		printf("%d\n", res[i]);
}
*/
