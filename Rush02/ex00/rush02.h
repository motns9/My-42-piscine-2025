/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gaeudes <gaeudes@made-f0Br6s11.clusters    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:21:51 by Gaeudes           #+#    #+#             */
/*   Updated: 2025/03/09 17:40:01 by jnonnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define ERR_NO_ARG	"Error\n"
# define ERR_DICT	"Dict Error\n"

# define BLOCK_SIZE 3
# define MAX_LEN_NB 39

# define F_VALID		0b001
# define F_KEEP_READ	0b010
# define F_MALLOC_ERROR	0b100

typedef struct s_parsing
{
	int					fd;
	int					b_read;
	char				r_char;
	int					read_0;
	int					read_minus;
	char				*buffer_cpy;
	char				**ptr_to_value;
	int					len_buff;
}	t_parsing;

typedef struct s_dict{
	unsigned int		flags;
	char				*n_0_9[10];
	char				*n_10_19[10];
	char				*n_20_90[8];
	char				*n_100;
	char				*n_p_1000[12];
	t_parsing			pars;
}	t_dict;

typedef struct s_r02{
	t_dict	dict;
	char	*dict_file;
	char	*nb_to_trad;
	int		off_set;
	int		nb_len;
	int		i_print;
	int		error_write;
	int		valid;
}	t_r02;

int			is_whitespace(char c);
int			is_number(char c);
int			is_printable(char c);
int			ft_strcmp(char *s1, char *s2);
void		realloc_cpy(t_dict *dc);

int			open_dict(t_dict *dc, char *file_name);
void		check_dict_full(t_dict *dc);
void		free_dict(t_dict *dc);
void		parse_dict(t_dict *dc, char *file_name);

void		update_flags_dc(t_dict *dc);
void		read_one(t_dict *dc);
void		find_key_adrr_value(t_dict *dc);

void		write_space(int	*start, int *err);
void		write_word(char *word, int *err);
void		print_nb(t_r02 *r02);

#endif
