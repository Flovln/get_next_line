/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 18:07:22 by fviolin           #+#    #+#             */
/*   Updated: 2016/01/07 11:40:14 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const	fd, char **line)
{
	static char *overflow;
	char		buf[BUFF_SIZE + 1];
	char		*str;
	int			ret;

	str = ft_strnew(200);
	ft_bzero(buf, BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0) // != 0 so not done reading
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0'; // fin de chaine apres le dernier caractere lu
		printf("Read %d bytes\n Content = ||%s||\n", ret, buf);
		//ft_strcpy(str, buf);
		ft_strcat(str, buf);
	}
	*line = str; // dire a str de pointer sur line, donc line prendra la valeur de str
	return (0);
}
