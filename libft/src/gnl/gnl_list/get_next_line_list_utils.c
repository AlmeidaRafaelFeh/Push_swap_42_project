/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:43:34 by rafreire          #+#    #+#             */
/*   Updated: 2025/09/11 13:50:52 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_list.h"

int	ft_newlst_add_back(t_gnline **lst, char *content)
{
	t_gnline	*new_list;
	t_gnline	*temp;

	new_list = malloc(sizeof(t_gnline));
	if (!new_list)
		return (0);
	new_list->content = ft_strdup(content);
	if (!new_list->content)
	{
		free(new_list);
		return (0);
	}
	new_list->next = NULL;
	if (!*lst)
	{
		*lst = new_list;
		return (1);
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new_list;
	return (1);
}

char	*ft_strdup(const char *str)
{
	char		*content;
	size_t		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		i++;
	content = malloc(i +1);
	if (!content)
		return (0);
	i = 0;
	while (str[i])
	{
		content[i] = str[i];
		i++;
	}
	content[i] = '\0';
	return (content);
}

void	ft_lstclear(t_gnline **lst)
{
	t_gnline	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

void	trim_stash(t_gnline **stash)
{
	t_gnline	*curr;
	t_gnline	*new;
	size_t		i;
	int			found;

	curr = *stash;
	new = NULL;
	found = 0;
	if (!stash || !*stash)
		return ;
	while (curr && !found)
	{
		i = 0;
		while (curr->content[i] != '\0')
		{
			if (curr->content[i] == '\n')
			{
				ft_newlst_add_back(&new, &curr->content[i + 1]);
				found = 1;
				break ;
			}
		i++;
		}
		if (!found)
			curr = curr->next;
	}
	if (found)
	{
		while (curr && curr->next)
		{
			curr = curr->next;
			ft_newlst_add_back(&new, curr->content);
		}
	}
	ft_lstclear(stash);
	*stash = new;
}
