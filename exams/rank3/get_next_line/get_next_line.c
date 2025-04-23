/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:00:35 by gtretiak          #+#    #+#             */
/*   Updated: 2025/04/06 17:45:45 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

int	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
int	ft_strchr(char *s, char c);
char	*ft_strdup(char *ref);

char	*ft_fill(char *tmp, char *buf, int fd)
{
	char	*new_tmp;
	int	bytes;

	bytes = 1;
	new_tmp = NULL;
	while (bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(tmp);
			break ;
		}
		buf[bytes] = '\0';
		if (bytes == 0)
			break ;
		new_tmp = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = new_tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (tmp);
}

char	*ft_take_line(char *new_tmp)
{
	char	*line;
	int	i;

	if (!new_tmp)
		return (NULL);
	i = 0;
	while (new_tmp[i] && new_tmp[i] != '\n')
		i++;
	if (new_tmp[i] == '\n')
		i++;
	line = ft_substr(new_tmp, 0, i);
	return (line);
}

char	*ft_take_rest(char *new_tmp)
{
	char	*rest;
	int	i;

	if (!new_tmp)
		return (NULL);
	i = 0;
	while (new_tmp[i] && new_tmp[i] != '\n')
		i++;
	if (new_tmp[i] != '\n')
	{
		free(new_tmp);
		return (NULL);
	}
	rest = ft_substr(new_tmp, i + 1, ft_strlen(new_tmp));
	free(new_tmp);
	return (rest);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char *tmp;
	char	*buf;
	char	*new_tmp;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!tmp)
		tmp = ft_strdup("");
	if (!tmp)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
	{
		free(tmp);
		return (NULL);
	}
	new_tmp = ft_fill(tmp, buf, fd);
	line = ft_take_line(new_tmp);
	tmp = ft_take_rest(new_tmp);
	return (line);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*res;
	int	i;

	if (!s || start >= len)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	i = 0;
	res = malloc(sizeof(char) * len - start + 1);
	if (!res)
		return (NULL);
	while (i + start < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int	i;
	int	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	res = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

char	*ft_strdup(char *ref)
{
	char	*res;
	int	l;
	int	i;

	if (!ref)
		return (NULL);
	l = ft_strlen(ref);
	i = 0;
	res = malloc(sizeof(char) * l + 1);
	if (!res)
		return (NULL);
	while (i < l)
	{
		res[i] = ref[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	int	fd;
	int	i;
	char	*s;

	i = 0;
	fd = open("tmp", O_RDWR | O_CREAT, 0644);
	if (fd == -1)
		exit (2);
	write(fd, "\n123\n456\n789", 12);
	lseek(fd, 0, SEEK_SET);
	while (i < 4)
	{
		s = get_next_line(fd);
		printf("The %d line:%s", i, s);
		free(s);
		i++;
	}
	close(fd);
}*/
