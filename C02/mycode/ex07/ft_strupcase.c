/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:02:23 by msbita            #+#    #+#             */
/*   Updated: 2025/02/27 17:56:21 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)

{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
	str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char str1[] = "salut";
	char str2[] = "42Paris";
	
	printf("Avant : %s\n", str1);
	ft_strupcase(str1);
	printf("Apres : %s\n", str1);
	printf("Avant : %s\n", str2);
	ft_strupcase(str2);
	printf("Apres : %s\n", str2);
	return (0);
}
*/
