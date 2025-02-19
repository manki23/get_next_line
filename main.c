/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:47:16 by manki             #+#    #+#             */
/*   Updated: 2018/01/15 16:13:31 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		main(int ac, char *av[])
{
	int		fd;
	char	*str;
	int		r;
	int		i;

	ac--;
	av++;
	str = NULL;
	if (ac == 1)
	{
		i = 0;
		r = 1;
		if ((fd = open(av[0], O_RDONLY)) == -1)
			return (-1);
		while (i < 10000000 && (r = get_next_line(fd, &str)) != 0)
		{
			i++;
			if (r == -1)
				ft_putstr("r == -1 => Erreur\n");
			else
				ft_putendl(str);
			ft_memdel((void **)&str);
		}
		if (r == 0)
			printf("r == 0 => Lecture terminée. %d lignes lues\n", i);
		if (str)
			ft_memdel((void **)&str);
		close(fd);
	}
	return (0);
}
