/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 11:18:10 by dboudy            #+#    #+#             */
/*   Updated: 2015/12/15 13:50:50 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		tab[4];
	int		i;
	int		fd;
	char	**retour;

	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		ft_putstr("open failed\n");
		return (0);
	}
	tab[0] = get_next_line(fd, retour);
	tab[1] = get_next_line(fd, retour);
	tab[2] = get_next_line(fd, retour);
	retour[4] = NULL;
	i = 0;
	while (tab[i])
	{
		printf("[%d]\n", tab[i]);
		i++;
	}
	i = 0;
	while (retour[i])
	{
		printf("[%s]\n", retour[i]);
		i++;
	}
	close(fd);
	return (0);
}