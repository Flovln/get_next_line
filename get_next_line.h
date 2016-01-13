/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 18:07:39 by fviolin           #+#    #+#             */
/*   Updated: 2016/01/13 11:27:05 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 99999

#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h> ////////////TEST A SUPPRIMER /////
#include <unistd.h>
#include <fcntl.h>

int		get_next_line(int const fd, char **line);

#endif
