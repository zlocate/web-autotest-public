/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:32:13 by rczarfun          #+#    #+#             */
/*   Updated: 2019/09/17 21:33:30 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **begin_list, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*tmp;

	if (*begin_list && *del)
	{
		list = *begin_list;
		while (list)
		{
			tmp = list;
			del(list->content, list->content_size);
			free(list);
			list = tmp->next;
		}
		*begin_list = NULL;
	}
}
