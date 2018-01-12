/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:19:49 by manki             #+#    #+#             */
/*   Updated: 2018/01/12 14:48:44 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

#include <stdio.h>

int		ft_fill_line(char **line, t_gnl *f)
{
	while (f->i < f->r)
	{
		f->len += 1;
		if (!(*line = ft_realloc(*line, f->len + 1)))
			return (-1);
		if (f->buf[f->i] == '\n')
		{
			f->i++;
			f->len = 0;
			return (1);
		}
		line[0][f->len - 1] = f->buf[f->i];
		line[0][f->len] = '\0';
		f->i++;
	}
	if (f->i == 0 && f->r == 0)
		return (0);
	return (2);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	f;
	int				result;

	if ((line == NULL) || (fd < 0))
		return (-1);
	*line = ft_strnew(0);
	result = 3;
	if ((f.i < f.r) && ((result = ft_fill_line(line, &f)) != 2))
		return (result);
	while (result == 3 || result == 2)
	{
		f.i = 0;
		if ((f.r = read(fd, f.buf, BUFF_SIZE)) == -1)
			return (-1);
		if (f.r == 0 && result == 2)
			return (1);
		result = ft_fill_line(line, &f);
		if (result != 2)
			return (result);
	}
	return (-1);
}
