/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:04:21 by msbita            #+#    #+#             */
/*   Updated: 2025/03/04 20:45:02 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	parite;
	int	nbr;

	parite = 0;
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str++;
	}
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			parite++;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		nbr *= 10;
		nbr += *str - 48;
		str++;
	}
	if (!(parite % 2))
		return (nbr);
	return (-nbr);
}
/*
int	main()
{
	char	*test = "	 ---+--+1234ab567";
	printf("%d\n" ,ft_atoi(test));
}
*/
