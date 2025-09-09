/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:43:31 by rafreire          #+#    #+#             */
/*   Updated: 2025/08/07 20:58:00 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 101
# endif

typedef struct s_gnline
{
	char			*content;
	struct s_gnline	*next;	
}	t_gnline;

char		*get_next_line(int fd);
char		*ft_get_line(t_gnline *stash);
char		*ft_strdup(const char *str);
int			found_newline(t_gnline *stash);
int			ft_newlst_add_back(t_gnline **lst, char *content);
void		ft_lstclear(t_gnline **lst);
void		read_and_stash(int fd, t_gnline **stash);
void		trim_stash(t_gnline **stash);
void		copy_line(t_gnline *stash, char *line, size_t max_len);
int			validate_trim(t_gnline *curr, t_gnline *new, int *i, int *found);

#endif