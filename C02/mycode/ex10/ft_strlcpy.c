/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:55:21 by msbita            #+#    #+#             */
/*   Updated: 2025/03/12 20:55:24 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
	{
		return (src_len);
	}
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
/*
int	main(void)
{
	char	src[] = "werenoi";
	char	dest[10];
	unsigned int	len;

	len = ft_strlcpy(dest, src, sizeof(dest));
	printf("copie: %s\n", dest);
	printf("Longueur de src: %d\n", len);
	return (0);
}
*/