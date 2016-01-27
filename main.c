/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:44:27 by fviolin           #+#    #+#             */
/*   Updated: 2016/01/24 16:13:00 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	int		ret_value;
	char	*line;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (ac > 1)
	if (fd == -1)
		return (-1);
	ret_value = 1;
	while (ret_value == 1)
	{
		ret_value = get_next_line(fd, &line);
		printf("%d || %s\n", ret_value, line);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
