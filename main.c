/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:47:16 by manki             #+#    #+#             */
/*   Updated: 2017/12/30 15:20:08 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

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
		i = 1;
		r = 1;
		if ((fd = open(av[0], O_RDONLY)) == -1)
			return (-1);
		while (i < 5 && (r = get_next_line(fd, &str)) != 0)
		{
			if (r == -1)
				ft_putstr("r == -1 => Erreur\n");
			else
			{
//				ft_putstr("ligne ");
//				ft_putnbr(i);
//				ft_putstr(" =>\t");
				ft_putstr(str);
				ft_putchar('\n');
//				ft_putstr("\n-------------\n");
				i++;
			}
			ft_memdel((void **)&str);
		}
		if (r == 0)
			ft_putstr("\nr == 0 => Lecture terminée.\n");
		if (str)
			ft_memdel((void **)&str);
		close(fd);
	}
	return (0);
}
