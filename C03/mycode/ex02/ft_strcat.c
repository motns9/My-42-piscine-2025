/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:19:22 by msbita            #+#    #+#             */
/*   Updated: 2025/03/02 15:54:06 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
	{
		i++;
	}
		j = 0;
	while (src[j])
	{
			dest[i] = src[j];
			i++;
			j++;
	}
		dest[i] = '\0';
	return (dest);
}
/*
int main() {
    char dest[20] = "Carre, ";
    char src[] = "La League";
    printf("Avant concatenation: %s\n", dest);
    ft_strcat(dest, src);
    printf("Apres concatenation: %s\n", dest);
    return 0;
}
*/
