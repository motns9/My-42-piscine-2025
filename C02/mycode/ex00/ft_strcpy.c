/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:25:58 by msbita            #+#    #+#             */
/*   Updated: 2025/02/26 17:51:58 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main()
{
        char src[] = "werenoi";
        char dest[20] = {0};

        printf("Avant: src = %s, dest = %s\n", src, dest);
        ft_strcpy(dest, src);
        printf("Apres: src = %s, dest = %s\n", src, dest);

        return 0;
}
*/
