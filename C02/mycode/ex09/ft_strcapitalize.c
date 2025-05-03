/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:10:10 by msbita            #+#    #+#             */
/*   Updated: 2025/03/08 16:16:35 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (new_word)
				str[i] -= 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (!new_word)
				str[i] += 32;
		}
		new_word = (str[i] < '0'
				|| (str[i] > '9' && str[i] < 'A')
				|| (str[i] > 'Z' && str[i] < 'a')
				|| str[i] > 'z');
		i++;
	}
	return (str);
}
/*
int main()
{
    char str[] = "Werenoi, cest carre !";
    printf("Avant: %s\n", str);
    ft_strcapitalize(str);
    printf("Apres: %s\n", str);
    return 0;
}
*/
