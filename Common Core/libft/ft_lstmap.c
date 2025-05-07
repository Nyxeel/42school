/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:25:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/05/07 19:56:20 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*current;

	head = NULL;
	current = NULL;
	head = ft_lstnew(f(lst->content));
	if (!head)
		return (ft_lstclear(&head, del), NULL);
	while (lst != NULL)
	{
		current = ft_lstnew(f(lst->content));
		if (!current)
			return (ft_lstclear(&current, del), NULL);
		ft_lstadd_back(&head, current);
		lst = lst->next;
	}
	return (head);
}


char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*hidden;
	unsigned int	i;

	i = 0;
	hidden = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!hidden)
		return (NULL);
	while (s[i])
	{
		hidden[i] = f(i, s[i]);
		i++;
	}
	hidden[i] = '\0';
	return (hidden);
}
