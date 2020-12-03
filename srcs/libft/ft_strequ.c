/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:47:30 by rczarfun          #+#    #+#             */
/*   Updated: 2019/09/16 19:51:26 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	if (ft_strcmp(s1, s2))
		return (0);
	else
		return (1);
}
