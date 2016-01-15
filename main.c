/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:44:27 by fviolin           #+#    #+#             */
/*   Updated: 2016/01/15 10:06:35 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*line;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	i = 1;
	while (i == 1)
	{
		i = get_next_line(fd, &line);
		printf("%d || %s\n", i, line);
	}
	close(fd);
	return (0);
}
