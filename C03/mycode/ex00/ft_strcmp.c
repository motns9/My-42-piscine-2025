/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:33:22 by msbita            #+#    #+#             */
/*   Updated: 2025/03/02 15:52:29 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
				i++;
	}
	return (0);
}
/*
int     main(void)
{
        char *s1 = "Werenoi";
        char *s2 = "Carre";

        int result = ft_strcmp(s1, s2);
        printf("Comparison result: %d\n", result);

        return (0);
}
*/
