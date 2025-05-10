/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mireyes- <mireyes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:01:30 by mireyes-          #+#    #+#             */
/*   Updated: 2025/03/02 18:03:09 by mireyes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H
# include <stdlib.h>
# include <unistd.h>

int		solve(int **grid, int values, int pos, int n);
void	ft_putstr(char *str);
int		**create_grid(int n);
void	free_grid(int **grille);
void	init_grid(int **grille);
void	print_grid(int **grille);
int		count_numbers(char *str);
int		*parse_input(char *str, int count);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		check_row(int **grid, int pos, int size, int n);
int		check_column(int **grid, int pos, int size, int n);
int		check_cross(int **grid, int pos, int size, int n);

#endif
