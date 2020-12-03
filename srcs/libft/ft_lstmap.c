/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:34:36 by rczarfun          #+#    #+#             */
/*   Updated: 2019/09/24 21:41:22 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new_list;

	if (lst && *f)
	{
		new_list = f(lst);
		if (new_list && lst->next)
			new_list->next = ft_lstmap(lst->next, f);
		return (new_list);
	}
	return (NULL);
}
