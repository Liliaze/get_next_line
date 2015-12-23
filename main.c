/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 12:48:28 by dboudy            #+#    #+#             */
/*   Updated: 2015/12/23 19:18:02 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int		main(int ac, char **av)
{
	char *test;
	char **line1;
	int	retour;
	int	fd;

	if (ac == 2)
	{
		fd = 0;
		retour = 1;
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			printf("open failed\n");
			return (0);
		}
		test = (char *)malloc(sizeof(test) * 50);
		line1 = &test;
		while (retour != 0)
		{
			retour = get_next_line(fd, line1);
		printf("retour in main : %d.", retour);
		printf("line in main = [%s]\n", line1[0]);
		}
		close(fd);
	}
	return (0);
}
