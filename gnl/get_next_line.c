/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:19:30 by gtretiak          #+#    #+#             */
/*   Updated: 2024/12/12 17:50:22 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_tmp(char *tmp, char *buf, int fd)
{
	ssize_t	x;
	char	*new_tmp;

	x = 1;
	while (x > 0)
	{
		x = read(fd, buf, BUFFER_SIZE);
		if (x == -1)
		{
			free(tmp);
			free(buf);
			return (NULL);
		}
		buf[x] = '\0';
		new_tmp = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = new_tmp;
		if (x == 0)
			break ;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (tmp);
}

char	*ft_get_line(char *tmp)
{
	char	*res;
	int		i;

	i = 0;
	if (tmp[0] == '\0')
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	res = ft_substr(tmp, 0, i + 1);
	if (tmp[i] == '\n')
		i++;
	res[i] = '\0';
	return (res);
}

char	*ft_take_rest(char *tmp)
{
	int		i;
	char	*new_tmp;

	i = 0;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	if (tmp[i] == '\0')
	{
		free(tmp);
		return (NULL);
	}
	new_tmp = ft_substr(tmp, i + 1, ft_strlen(tmp));
	free(tmp);
	return (new_tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*res;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!tmp)
		tmp = ft_strdup("");
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	tmp = ft_fill_tmp(tmp, buf, fd);
	if (!tmp)
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	res = ft_get_line(tmp);
	tmp = ft_take_rest(tmp);
	return (res);
}

static int	ft_countlines(const char *s, char c);

static int	ft_putstr_fd(char *s, int fd);

int	main(void)
{
	int	fd;
	int	newfd;
	int	i;
	char	*s = NULL;
	char	*str = "Numbers:777 666 111\nDec:0123456789\nHex:0123456789ABCDEF\nBin:01\0";
	size_t	written;
	int	words;
	
	fd = 0;
	i = 1;
	newfd = open("file.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (newfd == -1)
		printf("Error with a file: {-1}...program should stop...\n");
	else
		fd = newfd;
	written = ft_putstr_fd(str, fd);
	words = ft_countlines(str, '\n');
	lseek(fd, 0, SEEK_SET);
	if (written != ft_strlen(str))
		printf("Error writing to file\n");
	while (words)
	{
		s = get_next_line(fd);
		if (s == NULL)
			printf("Get_next_line returned NULL\n");
		else
			printf("Line %d:%s\n", i++, s);
		words--;
		free(s);
	}
}

static int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
        while (*s)
	{
                write(fd, s++, 1);
		i++;
	}
	return (i);
}

static int      ft_countlines(const char *s, char c)
{
        size_t  i;
        size_t  count;

        i = 0;
        count = 0;
	if (s[i] == c) 
		count++;
        while (s[i])
        {
                while (s[i] == c)
                        i++;
                if (s[i])
                        count++;
                while (s[i] && s[i] != c)
                        i++;
        }
        return (count);
}
