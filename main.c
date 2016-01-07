/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 10:20:08 by fviolin           #+#    #+#             */
/*   Updated: 2016/01/07 13:11:56 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int 	fd;
	int 	i;
	char 	*line;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (1);
	get_next_line(fd, &line);
	ft_putstr(line);
	close(fd);
	return (0);
}
