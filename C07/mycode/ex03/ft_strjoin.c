/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:35:28 by msbita            #+#    #+#             */
/*   Updated: 2025/03/12 20:36:45 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;

	if (size == 0)
		return (0);
	total_len = 0;
	i = -1;
	while (++i < size)
		total_len += ft_strlen(strs[i]);
	total_len += (size - 1) * ft_strlen(sep);
	return (total_len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	int		i;
	char	*result;
	char	*ptr;

	total_len = ft_total_len(size, strs, sep);
	result = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!result)
		return (NULL);
	ptr = result;
	i = 0;
	while (i < size)
	{
		ptr = ft_strcpy(ptr, strs[i]);
		ptr += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ptr = ft_strcpy(ptr, sep);
			ptr += ft_strlen(sep);
		}
		i++;
	}
	*ptr = '\0';
	return (result);
}

/*
int	main(void)
{
	char	*strs[] = {"Hello", "42", "Piscine"};
	char	*sep = " - ";
	char	*result;

	result = ft_strjoin(3, strs, sep);
	printf("Résultat: %s\n", result);
	free(result);
	return (0);
}
*/
