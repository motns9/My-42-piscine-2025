/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:32:23 by msbita            #+#    #+#             */
/*   Updated: 2025/02/27 19:38:29 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)

{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
	str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
/*
int main()
{
        char str[] = "WERENOI";
        printf("Original: %s\n", str);
        ft_strlowcase(str);
        printf("Apres: %s\n", str);
        return 0;
}
*/
