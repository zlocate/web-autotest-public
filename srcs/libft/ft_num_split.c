/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:29:13 by rczarfun          #+#    #+#             */
/*   Updated: 2020/01/29 19:29:58 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_num_ammount(char *s)
{
	int		i;
	int		ammount;

	i = 0;
	ammount = 0;
	while (s[i])
	{
		while ((s[i] == ' ' || s[i] == '\t') && s[i])
			i++;
		if (((s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '+')\
			&& s[i])
		{
			if (s[i] == '-' || s[i] == '+')
				i++;
			if ((s[i] >= '0' && s[i] <= '9') && s[i])
				ammount++;
			while (s[i] >= '0' && s[i] <= '9' && s[i])
				i++;
		}
		else if ((s[i] <= '0' || s[i] >= '9' || s[i] != '-' || s[i] != '+') \
				&& s[i])
			return (-1);
	}
	return (ammount);
}

int		*ft_num_split(char *s)
{
	int		ammount;
	int		i;
	int		k;
	int		*ret;

	ammount = ft_num_ammount(s);
	i = 0;
	k = 0;
	if (!(ret = (int *)ft_memalloc(sizeof(int) * ammount)))
		return (NULL);
	while (s[i])
	{
		while ((s[i] == ' ' || s[i] == '\t') && s[i])
			i++;
		if (k < ammount && s[i])
		{
			ret[k] = ft_atoi(&(s[i]));
			if (s[i] == '+' || s[i] == '-')
				i++;
			i += ft_num_len(ret[k]);
			k++;
		}
	}
	return (ret);
}
