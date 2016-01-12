/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 18:07:22 by fviolin           #+#    #+#             */
/*   Updated: 2016/01/12 15:38:02 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* gere la memoire des strings lues*/
/* concatene l'overflow de la premiere lecture avec la prochaine string (de la taille de BUFF_SIZE) jusqu'au premier\n rencontre et ainsi de suite*/

static int		ft_mem_concat(char *str, char *buf)
{
	if (!buf)
		return (1);
	ft_strjoin(str, buf);
	return (0);
}

/*  fait un ft_strchr sur le premier \n pour le remplacer par un \0*/
/* fait pointer *buf sur le premier caractere suivant le \0 (= overflow) */
/*
static int		ft_get_line(char **tmp, char **line)
{
	char *s;

	if ((s = ft_strchr(*tmp, '\n')))
	{
		*s = '\0';
		*line = ft_strdup(*tmp);
		ft_memove(*tmp, s + 1, ft_strlen(s + 1));
		return (1);
	}
	return (0);
}
*/
int				get_next_line(int const	fd, char **line)
{
	static char *overf; // excedent apres le premier \n de la premiere string
	char		buf[BUFF_SIZE + 1]; // stock la string lu par read
	char		*str; // pointe sur le premier char de la string lu
	int			ret; // valeur de ret du read

	ft_bzero(buf, BUFF_SIZE);
	ft_bzero(str, BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0) // tant que l'on a pas atteint EOF (\0 = 0)
	{
		if (ret == -1)
			return(-1);
		buf[ret] = '\0';
		printf("\nRead %d bytes\nContent = ||%s||\n", ret, buf);
		ft_mem_concat(str, buf);
	}
	*line = str;
	return (0);
}
