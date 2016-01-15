/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 18:07:22 by fviolin           #+#    #+#             */
/*   Updated: 2016/01/14 16:41:42 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_mem_concat(char *str, char *buf)
{
	char *tmp;

	tmp = ft_strjoin(str, buf);
	free(str);
	str = NULL;
	return (tmp);
}

static int		ft_get_line(char **line, char *buf, char *overf)
{
	char *tmp;

	if ((tmp = ft_strchr(buf, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(buf);
		ft_memmove(overf, tmp + 1, ft_strlen(tmp + 1) + 1);
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char overf[BUFF_SIZE + 1];
	char		buf[BUFF_SIZE + 1];
	char		*str;
	int			ret;

	if (ft_get_line(line, overf, overf) == 1)
		return (1);
	str = ft_strdup(overf);
	ft_bzero(buf, BUFF_SIZE + 1);
	ft_bzero(overf, BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		str = ft_mem_concat(str, buf);
		if (ft_get_line(line, str, overf) == 1)
		{
			free(str);
			str = NULL;
			return (1);
		}
	}
	ft_bzero(overf, BUFF_SIZE + 1);
	*line = str; // si on nous passe 1 string sans \n (avec EOF a la fin) alors on la stock directement dans *line,
	free(str);
	str = NULL;
	return (0);
}
