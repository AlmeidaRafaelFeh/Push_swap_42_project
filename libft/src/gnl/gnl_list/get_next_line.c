/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:42:53 by rafreire          #+#    #+#             */
/*   Updated: 2025/08/16 18:30:36 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnline	*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_and_stash(fd, &stash);
	if (!stash || !stash->content)
		return (NULL);
	line = ft_get_line(stash);
	if (!line || line[0] == '\0')
	{
		free (line);
		ft_lstclear(&stash);
		return (NULL);
	}
	trim_stash(&stash);
	return (line);
}

void	read_and_stash(int fd, t_gnline **stash)
{
	char		*buffer;
	ssize_t		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	bytes_read = 1;
	while (!found_newline(*stash) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			ft_lstclear(stash);
			break;
		}
		buffer[bytes_read] = '\0';
		if (!ft_newlst_add_back(stash, buffer))
		{
			free(buffer);
			ft_lstclear(stash);
			return ;
		}
	}
	free(buffer);
}

int	found_newline(t_gnline *stash)
{
	size_t		i;
	t_gnline	*current;

	current = stash;
	
	while (current)
	{
		i = 0;
		if(!current->content)
			break;
		while (current->content[i])
		{
			if (current->content[i] == '\n')
				return (1);
			i++;
		}
		current = current->next;
	}
	return (0);
}

char	*ft_get_line(t_gnline *stash)
{
	char		*line;
	t_gnline	*current;
	size_t		total_len;
	size_t		i;

	total_len = 0;
	current = stash;
	while (current != NULL)
	{
		i = 0;
		while (current->content[i])
		{
			total_len++;
			if (current->content[i] == '\n')
				break ;
		i++;
		}
	current = current->next;
	}
	line = malloc(total_len +1);
	if (!line)
		return (NULL);
	copy_line(stash, line, total_len);
	return (line);
}

void	copy_line(t_gnline *stash, char *line, size_t max_len)
{
	size_t			i;
	size_t			j;
	t_gnline		*current;

	j = 0;
	current = stash;
	while (current && j < max_len)
	{
		i = 0;
		while (current->content[i] && j < max_len)
		{
			line[j] = current->content[i];
			if (current->content[i] == '\n')
			{
				j++;
				break ;
			}
		j++;
		i++;
		}
	current = current->next;
	}
	line[j] = '\0';
}

// #include <stdio.h>
// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     int fd3;
// 	char *str;
	
//     fd3 = open("test_files/43_with_nl", O_RDONLY);
// 	str = get_next_line(fd3);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd3);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd3);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd3);
// 	printf("%s", str);
// 	free(str);
//     return 0;
// }
