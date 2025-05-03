/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:58:25 by msbita            #+#    #+#             */
/*   Updated: 2025/03/05 15:53:13 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
		ptr++;
	return (ptr - str);
}
/*
int	main()
{
	char	*str = "Werenoi";
	int	longueur = ft_strlen(str);
	printf("longueur de '%s': %d\n", str, longueur);
	return (0);
}
*/
