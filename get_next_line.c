/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:11:15 by gpouzet           #+#    #+#             */
/*   Updated: 2022/12/08 15:40:58 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*next_line(char	*file)
{
	char	*tmp;

	if (!file)
		return (0);
	tmp = ft_strchr(file, '\n');
	if (tmp)
		return (ft_substr(file, 0, ft_strlen(file) - ft_strlen(tmp) + 1));
	return (0);
}

static char	*reset(char	*file)
{
	char	*tmpa;
	char	*tmpb;

	tmpa = ft_strchr(file, '\n');
	if (*(tmpa + 1))
		tmpb = ft_substr(tmpa, 1, ft_strlen(file));
	else
		tmpb = 0;
	free(file);
	return (tmpb);
}

static char	*append(char *file, char *reading)
{
	char	*tmp;

	if (!file)
		return (ft_substr(reading, 0, ft_strlen(reading)));
	tmp = ft_join(file, reading);
	free(file);
	return (tmp);
}

static char	*endfile(char **file)
{
	char	*tmp;

	if (!file || !(*file))
		return (NULL);
	tmp = ft_substr(*file, 0, ft_strlen(*file));
	free(*file);
	*file = NULL;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*file = NULL;
	char		*reading;
	char		*line;

	line = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	reading = malloc(BUFFER_SIZE + 1);
	while (!line)
	{
		line = next_line(file);
		if (line)
			file = reset(file);
		if (line)
			break ;
		ft_memset(reading, '\0', BUFFER_SIZE + 1);
		if (read(fd, reading, BUFFER_SIZE) <= 0)
		{
			free(reading);
			return (endfile(&file));
		}
		file = append(file, reading);
	}
	free(reading);
	return (line);
}
