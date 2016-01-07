/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 12:40:08 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/07 14:47:00 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./get_next_line.h"

static int		result(int etat)
{
	if (etat == 0)
		return (0);
	else if (etat < 0)
		return (-1);
	return (1);
}

static char	*ft_read_buffer(int fd, char *buf)
{
	int		ret;
	int		len;
	char	*new;

	ret = 0;
	len = 0;
	if (buf != NULL)
		len = ft_strlen(buf);
	if ((new = (char *)malloc(sizeof(char *) * (BUFF_SIZE + len + 1))) == NULL)
		return (NULL);
	if (buf != NULL)
		new = ft_strcpy(new, buf);
	free(buf);
	buf = NULL;
	if ((ret = read(fd, new + len, BUFF_SIZE)) == -1)
		return (NULL);
	new[ret + len] = '\0';
	if (ret == 0 && len == 0)
	{
		free(new);
		new = NULL;
	}
	return (new);
}

static char	**copy_line(char **line, char *buf, char *n)
{
	int	i;

	i = 0;
	if (n == NULL)
		return (line);
	while (buf[i] != n[0])
	{
		line[0][i] = buf[i];
		i++;
	}
	line[0][i] = '\0';
	return (line);
}

static char	*save_new_buf(char *buf, char *n)
{
	int	i;
	int i2;

	i = 0;
	i2 = 0;
	while (buf[i] != n[0])
		i++;
	i++;
	while (buf[i])
	{
		buf[i2] = buf[i];
		i++;
		i2++;

	}
	buf[i2] = buf[i];
	return (buf);
}

int		get_next_line(int const fd, char **line)
{
	static char		*buf[258];
	char			*check_n;

	if (fd < 0 || fd > 257)
		return (-1);
	while (check_n == NULL)
	{
		if (buf[fd] != NULL)
			check_n = ft_strchr(buf[fd], '\n');
		if (check_n != NULL)
		{
				line = copy_line(line, buf[fd], check_n);
				buf[fd] = save_new_buf(buf[fd], check_n);
		}
		else if (buf[fd] == NULL || check_n == NULL)
		{
			if ((buf[fd] = ft_read_buffer(fd, buf[fd])) == NULL)
				return (-1);
		}
	}
	check_n = NULL;
	return (1);
}
