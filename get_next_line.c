/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 18:07:22 by fviolin           #+#    #+#             */
/*   Updated: 2016/01/12 18:10:01 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* gestion memoire + concatenation */

static char		*ft_mem_concat(char *str, char *buf)
{
	char *tmp;

	tmp = ft_strjoin(str, buf);
	return (tmp);
}

static int		ft_get_line(char **line, char *buf, char *overf)
{
	char *tmp;

	if ((tmp = ft_strchr(buf, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(buf);
		ft_memmove(overf, tmp + 1, ft_strlen(tmp + 1) + 1); //recuperer l'overflow
		return (1);
	}
	return (0);
}

int				get_next_line(int const	fd, char **line)
{
	static char overf[BUFF_SIZE + 1];
	char		buf[BUFF_SIZE + 1];
	char		*str;
	int			ret;

	ft_bzero(buf, BUFF_SIZE);
	if (ft_get_line(line, overf, overf) == 1)
		return (1);
	str = ft_strdup(overf);
	ft_bzero(buf, BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0) // tant que l'on a pas atteint EOF (= 0)
	{
		if (ret == -1)
			return (-1);
		//printf("\nRead %d bytes\n\nContent = ||%s||\n", ret, buf);
		buf[ret] = '\0';
		str = ft_mem_concat(str, buf);
		if (ft_get_line(line, str, overf) == 1)
			return (1);
		//ft_putstr("\nContenu de line dans gnl : ");
		//ft_putstr(*line);
		//printf("\nContenu de line dans gnl : %s\n ", *line);
		//printf("\nContenu de overf dans gnl : %s\n ", overf);
	}
	//free(str);
	*line = NULL; // OU *line = ft_strnew(1)
	return (0);
}
