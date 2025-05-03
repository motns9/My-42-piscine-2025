/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 23:08:48 by msbita            #+#    #+#             */
/*   Updated: 2025/03/10 23:08:50 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	return (nb * ft_recursive_power(nb, power - 1));
}
/*
int	main()
{
	printf("%d\n", ft_recursive_power(8, 3));
	printf("%d\n", ft_recursive_power(8, 3));
	printf("%d\n", ft_recursive_power(8, 3));
	printf("%d\n", ft_recursive_power(8, 3));
	return (0);
}
*/
