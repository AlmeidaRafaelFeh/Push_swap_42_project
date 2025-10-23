/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:06:51 by rafreire          #+#    #+#             */
/*   Updated: 2025/10/23 19:27:16 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}	t_stacks;

typedef enum e_location
{
	TOP_A,
	BOT_A,
	TOP_B,
	BOT_B
}	t_location;

typedef struct s_chunk_info
{
	int			chunk_size;
	int			min_value;
	int			med_value;
	int			max_value;
}	t_chunk_info;

char			*parse_args(int ac, char *av[]);
int				ft_only_number(char *str);
int				numbers_len(char *str);
int				is_min_max(long *str, int len);
int				ft_check_duplicates(long *numbers, int len);
int				*numbers_valid(char *str, int len_numbers);
int				get_top_value(t_stacks *stacks, int location);
int				exists_in_stack(t_stacks *stacks,
					int location, int min, int max);
int				find_cheaper(t_stacks *stacks);
int				find_at_start(t_stacks *stacks);
int				find_at_end(t_stacks *stacks);
long			ft_atol(const char *nptr);
void			new_stack_index(int *stack, int *size);
void			copy_stack_aux(int *stack, int *aux, int *size);
void			mensage_error(void);
void			mensage_error_free(int *stack);
void			mensage_error_free_long(long *stack);
void			mensage_error_free_struct(t_stacks *stacks);
void			clean_copy_arr(long *numbers, char *str);
void			create_struct_stacks(t_stacks *stacks, int *stack, int size);
void			two_numbers_a(t_stacks *stacks);
void			three_numbers_a(t_stacks *stacks);
void			two_numbers_b(t_stacks *stacks);
void			three_numbers_b(t_stacks *stacks);
void			base_cases(t_stacks *stacks);
void			five_numbers(t_stacks *stacks);
void			rotate_chunk(t_stacks *stacks, int location);
void			push_to(int from, int to, t_stacks *stacks);
void			ordenate_stack_b(t_stacks *stacks);
void			lower_cases(t_stacks *stacks, int location, int min, int max);
void			recursive_sort(t_stacks *stacks, int min,
					int max, int location);
void			split_chunk(t_stacks *stacks, t_chunk_info info, int location);
void			move_cheaper_first(t_stacks *stacks, int location,
					int min, int max);
t_chunk_info	get_chunk_info(int min, int max);

//.......................PUSH_SWAP INSTRUCTIONS.......................

void			push_a(t_stacks *stacks);
void			push_b(t_stacks *stacks);
void			swap_a(t_stacks *stacks);
void			swap_b(t_stacks *stacks);
void			swap_ss(t_stacks *stacks);
void			rotate_b(t_stacks *stacks);
void			rotate_a(t_stacks *stacks);
void			rrotate_a(t_stacks *stacks);
void			rrotate_b(t_stacks *stacks);
void			rrrotate(t_stacks *stacks);

#endif