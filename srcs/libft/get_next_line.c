/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:44:18 by rczarfun          #+#    #+#             */
/*   Updated: 2019/11/06 03:10:42 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	jointoline(char **s, char **line)
{
	char	*tmp;
	char	*pointtoendl;

	if ((pointtoendl = ft_strchr(*s, '\n')))
	{
		*line = ft_strsub(*s, 0, pointtoendl - *s);
		tmp = ft_strdup(&((*s)[pointtoendl - *s + 1]));
		free(*s);
		*s = tmp;
		if (**s == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
}

static void	joinbuff(char **s, int ret, char *buff)
{
	char	*tmp;

	buff[ret] = '\0';
	if (*s == NULL)
	{
		if(!(*s = ft_strdup(buff)))
			exit(0);
	}
	else
	{
		tmp = ft_strjoin(*s, buff);
		free(*s);
		*s = tmp;
	}
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*s[OPEN_MAX];
	char		buff[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL)
		exit(0);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		joinbuff(&s[fd], ret, buff);
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	if (ret < 0)
		exit(0);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	else
	{
		jointoline(&s[fd], line);
		return (1);
	}
}
