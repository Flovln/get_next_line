/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 18:07:39 by fviolin           #+#    #+#             */
/*   Updated: 2016/01/07 13:11:30 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 5

#include "libft/libft.h"
#include <stdlib.h> //////////////////TEST
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int		get_next_line(int const fd, char **line);

#endif
