/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 18:07:22 by fviolin           #+#    #+#             */
/*   Updated: 2016/01/04 16:45:50 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"



void	*ft_realloc(void *ptr, size_t size)
{
	void	*str;

	str = ft_memalloc(size);
	if (ptr)
	{
		if (str)
			ft_memcpy(str, ptr, size);
		ft_memdel(&ptr);
	}
	return (str);
}
/*
int		get_next_line(int const	fd, char **line)
{
	static char *buf;
}
*/

int		main()
{
	char	*s;

	s = (char *)malloc(sizeof(char));
	strcpy(s, "hellobeautiful");
	printf("Allocation de memoire\n");
	printf("String = %s, Address = %p\n", s, s);

	//s = (char *)realloc(s, sizeof(char));
	strcat(s, "world.com");
	printf("Reallocation de memoire\n");
	printf("String = %s, Address = %p\n", s, s);

	free(s);

	return (0);
}
