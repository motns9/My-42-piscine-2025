/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 04:24:59 by msbita            #+#    #+#             */
/*   Updated: 2025/03/13 04:46:03 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define EVEN(n) ((n) % 2 == 0)
# define SUCCESS 0
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"

typedef int	t_bool;

#endif
/*
#include "ft_boolean.h"

void ft_putstr(char str)
{
    while (str)
        write(1, str++, 1);
}

t_bool ft_is_even(int nbr)
{
    return (EVEN(nbr) ? TRUE : FALSE);
}
/*
int main(int argc, char *argv[])
{
    (void)argv;
    if (ft_is_even(argc - 1) == TRUE)
        ft_putstr(EVEN_MSG);
    else
        ft_putstr(ODD_MSG);
    return (SUCCESS);
	gcc main.c -o test && ./test a b
}
*/
