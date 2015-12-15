/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 11:12:03 by dboudy            #+#    #+#             */
/*   Updated: 2015/12/15 16:17:15 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	int		ret;
	int		len;
	int		i;
	char 	*buf;
	char 	*tmp;

	buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while (ret > 0 && i <= BUFF_SIZE)
	{
		ret = read(fd, buf, BUFF_SIZE);
	}
	buf[BUFF_SIZE + 1] = '\0';
	len = 0;
	while (buf[len] != '\n' && buf[len])
	{
		len++;
	}
	tmp = (char *)malloc(sizeof(char) * len);
	buf[len] = '\0';
	i = 0;
	while (buf[i])
	{
		tmp[i] = buf[i];
		i++;
	}
	tmp[i] = buf[i];
	if (ret > 0)
		return (1);
	else if (ret == 0)
		return (0);
	else
		return (-1);
}
