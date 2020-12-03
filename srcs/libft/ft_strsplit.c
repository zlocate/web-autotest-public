/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:07:09 by rczarfun          #+#    #+#             */
/*   Updated: 2019/09/17 21:55:19 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**the_creator(const char *s, char c, int ammo, int len)
{
	char	**ret;
	int		i;
	int		j;
	int		k;

	if (!(ret = (char **)ft_memalloc(sizeof(*ret) * (ammo + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			if (!(ret[j] = (char *)ft_memalloc(sizeof(**ret) * (len + 1))))
				return (NULL);
			i--;
			while (s[++i] != c && s[i])
				ret[j][k++] = s[i];
			j++;
		}
	}
	return (ret);
}

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	int		max_len;
	int		ammount;
	int		current;

	if (!s || !c)
		return (NULL);
	i = 0;
	max_len = 0;
	ammount = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			ammount++;
			current = 0;
			i--;
			while (s[++i] != c && s[i])
				current++;
			max_len = (max_len < current) ? current : max_len;
		}
	}
	return (the_creator(s, c, ammount, max_len));
}
