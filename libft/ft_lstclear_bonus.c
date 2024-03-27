/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:25:26 by onault            #+#    #+#             */
/*   Updated: 2024/02/17 15:39:34 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ls;

	ls = *lst;
	if (!*lst)
		return ;
	while (ls != NULL)
	{
		*lst = ls->next;
		del(ls->content);
		free(ls);
		ls = *lst;
	}
	*lst = NULL;
}
