/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 11:12:03 by dboudy            #+#    #+#             */
/*   Updated: 2015/12/15 13:56:16 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	int		ret;
	
	ret = read(fd, *line, 20);
	ft_putstr("fd dans get : ");
	if (ret > 0)
		return (1);
	else if (ret == 0)
		return (0);
	else
		return (-1);
}
