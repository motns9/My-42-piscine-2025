/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:40:51 by msbita            #+#    #+#             */
/*   Updated: 2025/03/10 22:46:00 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0 || nb == 1)
	{
		return (1);
	}
	return (nb * ft_recursive_factorial(nb - 1));
}
/*
int	main()
{
	printf("%d\n", ft_recursive_factorial(8));
	printf("%d\n", ft_recursive_factorial(8));
	printf("%d\n", ft_recursive_factorial(8));
	printf("%d\n", ft_recursive_factorial(8));
	printf("%d\n", ft_recursive_factorial(8));
	printf("%d\n", ft_recursive_factorial(8));
	return (0);
}
*/
