/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:06:51 by rafreire          #+#    #+#             */
/*   Updated: 2025/09/13 20:56:15 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/includes/libft.h"

char	*parse_args(int ac, char *av[]);
int		ft_only_number(char *str);
int		numbers_len(char *str);
int		is_min_max(long *str, int len);
int		ft_check_duplicates(long *numbers, int len);
long	ft_atol(const char *nptr);
long	*numbers_valid(char *str, int len_numbers);
void	mensage_error(void);
void	clean_copy_arr(long *numbers, char *str);

//.......................PUSH_SWAP INSTRUCTIONS.......................

void	push_a(long *stack_a, long *stack_b, int *size_a, int *size_b);
void	push_b(long *stack_a, long *stack_b, int *size_a, int *size_b);

#endif