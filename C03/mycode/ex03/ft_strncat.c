/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:17:47 by msbita            #+#    #+#             */
/*   Updated: 2025/03/02 15:54:48 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	dest_len;

	dest_len = 0;
	while (dest[dest_len])
		dest_len++;
	i = 0;
	while (i < nb && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
/*
int main()
{
    char dest[20] = "PNL, ";
    char src[] = "Lacrim !";
    unsigned int nb = 6;

    printf("Avant concatenation: %s\n", dest);
    ft_strncat(dest, src, nb);
    printf("Apres concatenation: %s\n", dest);

    return 0;
}
*/
