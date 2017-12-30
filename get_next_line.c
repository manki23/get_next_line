/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:19:49 by manki             #+#    #+#             */
/*   Updated: 2017/12/30 15:23:02 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*tmp;
	int		i;

	if (size < 1 && ptr)
		ft_memdel(&ptr);
	else
	{
		tmp = ptr;
		if (!(ptr = ft_memalloc(size + 1)))
			return (NULL);
		if (tmp)
		{
			i = -1;
			while (*(char *)(tmp + (++i)))
				*(char *)(ptr + i) = *(char *)(tmp + i);
			ft_memdel((void **)&tmp);
		}
	}
	return (ptr);
}

char	*ft_char_cat(char *s1, char c)
{
	int		i;

	i = 0;
	while (s1[i])
		i++;
	s1[i] = c;
	return (s1);
}

int		get_next_line(const int fd, char **line)
{
	static int	r;
	static char	tmp[BUFF_SIZE];
	int			i;
	static int	len;

	if (r > 0)
	{
	}
	while ((r = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		i = -1;
		while (tmp[++i] != '\n' && tmp[i])
		{
			len += 1;
			if (!(*line = ft_realloc(*line, len)))
				return (-1);
			*line = ft_char_cat(*line, tmp[i]);
			r--;
		}
		if (tmp[i] == '\n')
			return (1);
	}
	if (r == 0)
		return (0);
	return (1);
}
