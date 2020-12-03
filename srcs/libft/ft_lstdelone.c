/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:25:11 by rczarfun          #+#    #+#             */
/*   Updated: 2019/09/17 21:25:11 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **begin_list, void (*del)(void *, size_t))
{
	t_list	*list;

	if (*begin_list && *del)
	{
		list = *begin_list;
		del(list->content, list->content_size);
		free(list);
		*begin_list = NULL;
	}
}
