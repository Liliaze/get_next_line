/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:54:33 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/22 14:23:18 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 65

# include <unistd.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"

int		get_next_line(int const fd, char **line);

#endif
