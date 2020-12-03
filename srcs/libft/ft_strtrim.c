/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:32:58 by rczarfun          #+#    #+#             */
/*   Updated: 2019/09/19 08:58:12 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while ((s[i] <= ' ') && (s[i]))
		i++;
	while ((s[j] <= ' ') && (j >= i))
		j--;
	if (!*s || ((j - i) == 0))
		return ("");
	return (ft_strsub(s, i, (j - i + 1)));
}
