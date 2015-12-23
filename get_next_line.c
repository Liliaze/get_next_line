/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 12:57:31 by dboudy            #+#    #+#             */
/*   Updated: 2015/12/23 19:33:21 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_return_get(char *line, char *buf)
{
	int	len;

	len = ft_strlen(line);
	printf("len de line cree = '%d'", len);
	if (len > 0)
		return (1);
	else if (len == 0 && buf != NULL)
		return (1);
	else if (len == 0 && buf == NULL)
		return (0);
	else
		return (-1);
}

char	*ft_realloc_get(char *new, int len)
{
	char	*tmp;
	int 	i;

	i = 0;
	if ((tmp = (char *)malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	tmp[len] = '\0';
	tmp = ft_strcpy(tmp, new);
	if ((new = (char *)malloc(sizeof(char *) * (len + BUFF_SIZE + 1))) == NULL)
		return (NULL);
	new[len + BUFF_SIZE] = '\0';
	new = ft_strcpy(new, tmp);
	free(tmp);
	tmp = NULL;
	return (new);
}

char	*ft_read_file(int fd, char *buf)
{
	int	ret;
	int	len;

	len = 0;
	ret = BUFF_SIZE;
	if ((buf = (char *)malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	while (ret == BUFF_SIZE)
	{
		buf = ft_realloc_get(buf, len);
		if (buf == NULL)
			return (buf);
		len = ft_strlen(buf);
		ret = read(fd, (buf + len), BUFF_SIZE);
		buf[ret + len] = '\0';
	}
	return (buf);
}

int		get_next_line(int const fd, char **line)
{
	static char		*buf;
	char			*i_end;
	
	if (buf == NULL)
	{
		if ((buf = ft_read_file(fd, buf)) == NULL)
			return (-1);
	}
	i_end = ft_strchr(buf, '\n');
	if (i_end != NULL)
	{
		i_end[0] = '\0';
		*line = ft_strcpy(*line, buf);
		buf = i_end + 1;
	}
	else
	{
		*line = ft_strcpy(*line, buf);
		buf = NULL;
		free(buf);
	}
	return (ft_return_get(*line, buf));
}
