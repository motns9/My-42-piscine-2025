/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonaci.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 23:14:58 by msbita            #+#    #+#             */
/*   Updated: 2025/03/10 23:15:00 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
	{
		return (-1);
	}
	if (index == 0)
	{
		return (0);
	}
	if (index == 1)
	{
		return (1);
	}
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*
int	main()
{
	printf("%d\n", ft_fibonacci(8));
	printf("%d\n", ft_fibonacci(8));
	printf("%d\n", ft_fibonacci(8));
	printf("%d\n", ft_fibonacci(8));
	return (0);
}
*/
