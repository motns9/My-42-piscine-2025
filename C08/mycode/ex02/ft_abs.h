/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 04:34:15 by msbita            #+#    #+#             */
/*   Updated: 2025/03/13 04:48:46 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(Value) ((Value) < 0 ? -(Value) : (Value))

#endif

/*
#include <stdio.h>
#include "ft_abs.h"

int main()
{
    printf("ABS(-5) = %d\n", ABS(-5));
    printf("ABS(0) = %d\n", ABS(0));
    printf("ABS(10) = %d\n", ABS(10));
    printf("ABS(-42) = %d\n", ABS(-42));
    printf("ABS(-3 + 2) = %d\n", ABS(-3 + 2)); // Test avec une expression

    return 0;
}
	gcc main.c -o test && ./test
*/
