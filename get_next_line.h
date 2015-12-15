/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 11:10:48 by dboudy            #+#    #+#             */
/*   Updated: 2015/12/15 15:46:41 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 9999

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>

int		get_next_line(int const fd, char **line);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int i);

#endif
