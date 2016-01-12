/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 18:07:22 by fviolin           #+#    #+#             */
/*   Updated: 2016/01/12 17:02:15 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* gestion memoire + concatenation */

static char		*ft_mem_concat(char *str, char *buf)
{
	char *tmp;

	tmp = ft_strnew(BUFF_SIZE + 1);
	tmp = ft_strjoin(str, buf);
	return (tmp);
}

static int		ft_get_line(char **line, char *str)
{
	char *tmp;

	if ((tmp = ft_strchr(str, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(str);
		ft_memmove(str, tmp + 1, ft_strlen(tmp + 1) + 1);
		return (1);
	}
	return (0);
}

int				get_next_line(int const	fd, char **line)
{
	//static char *overf;
	char		buf[BUFF_SIZE + 1];
	char		*str;
	int			ret;

	ft_bzero(str, BUFF_SIZE);
	ft_bzero(buf, BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0) // tant que l'on a pas atteint EOF (= 0)
	{
		if (ret == -1)
			return (-1);
		printf("\nRead %d bytes\n\nContent = ||%s||\n", ret, buf);
		str = ft_mem_concat(str, buf);
		ft_get_line(line, str);
		printf("\nContenu de line dans gnl : %s\n ", *line);
		printf("\nContenu de str dans gnl : %s\n ", str);
	}
	//free(str);
	return (0);
}
