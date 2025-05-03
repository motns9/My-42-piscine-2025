/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 23:16:30 by msbita            #+#    #+#             */
/*   Updated: 2025/03/11 14:01:27 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb)
{
	int	x;

	x = 1;
	if (nb < 0)
		return (0);
	while (x * x <= nb && x <= 46340)
	{
		if (x * x == nb)
			return (x);
		x++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(9));
	printf("%d\n", ft_sqrt(16));
	printf("%d\n", ft_sqrt(25));
	printf("%d\n", ft_sqrt(36));
	printf("%d\n", ft_sqrt(50));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(-4));
	return (0);
}
*/
