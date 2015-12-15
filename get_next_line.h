/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 11:10:48 by dboudy            #+#    #+#             */
/*   Updated: 2015/12/15 13:51:26 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>

int		get_next_line(int const fd, char **line);
void	ft_putstr(char *str);

#endif
