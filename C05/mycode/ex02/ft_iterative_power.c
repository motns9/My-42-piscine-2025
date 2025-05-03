/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:55:24 by msbita            #+#    #+#             */
/*   Updated: 2025/03/10 23:02:51 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
	{
		return (0);
	}
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}
/*
int	main()
{
	printf("%d\n", ft_iterative_power(8, 3));
	printf("%d\n", ft_iterative_power(8, 3));
	printf("%d\n", ft_iterative_power(8, 3));
	return (0);
}
*/
