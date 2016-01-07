/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 18:07:22 by fviolin           #+#    #+#             */
/*   Updated: 2016/01/07 16:47:33 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_mem_concat(char *dst, char *src)
{
	char *res;

	if (!res)
		return (NULL);
	res = (ft_strnew(ft_strlen(dst) + ft_strlen(src) + 1));
	ft_strcat(dst, src);
	return (res);
}

static char		get_line(char **line, char **tmp)
{
	char *str;

	if ((str = ft_strchr(*tmp, '\n')))
	{
		*str = '\0';
		*line = ft_strdup(*tmp);
		return (1);
	}
	return (0);
}
int				get_next_line(int const	fd, char **line)
{
	static char *overflow;
	char		buf[BUFF_SIZE + 1];
	char		*str;
	int			ret;

	ft_bzero(str, BUFF_SIZE);
	ft_bzero(buf, BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		printf("Read %d bytes\n Content = ||%s||\n", ret, buf);
		ft_mem_concat(str, buf);
	}
	*line = str;
	return (0);
}
