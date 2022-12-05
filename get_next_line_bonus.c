/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:19:40 by gpouzet           #+#    #+#             */
/*   Updated: 2022/11/28 21:44:05 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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

static char	*endfile(char **file, char *reading)
{
	char	*tmp;

	free(reading);
	if (!file || !(*file))
		return (NULL);
	tmp = ft_substr(*file, 0, ft_strlen(*file));
	free(*file);
	*file = NULL;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*file[1024] = {NULL};
	char		*reading;
	char		*line;
	int			readed;

	line = NULL;
	reading = malloc(BUFFER_SIZE + 1);
	while (!line)
	{
		line = next_line(file[fd]);
		if (line)
			file[fd] = reset(file[fd]);
		else
		{
			ft_memset(reading, '\0', BUFFER_SIZE + 1);
			readed = read(fd, reading, BUFFER_SIZE);
			if (*reading)
				file[fd] = append(file[fd], reading);
			if (readed <= 0)
				return (endfile(&file[fd], reading));
		}
	}
	free(reading);
	return (line);
}
