/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:33:43 by rczarfun          #+#    #+#             */
/*   Updated: 2019/09/16 19:37:59 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	if (!(ret = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		ret[i] = f(s[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
