/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:03:43 by rczarfun          #+#    #+#             */
/*   Updated: 2019/09/17 22:27:59 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	if (!s || !(ret = ft_strnew(len)))
		exit(0);
	i = 0;
	while (i < len)
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	return (ret);
}
