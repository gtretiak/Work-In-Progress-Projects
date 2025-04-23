/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:41:54 by gtretiak          #+#    #+#             */
/*   Updated: 2024/12/12 17:56:58 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	char		*res;
	char		*buf;
	static char	*tmp[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!tmp[fd])
		tmp[fd] = ft_strdup("");
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	tmp[fd] = ft_fill_tmp(tmp[fd], buf, fd);
	if (!tmp[fd])
	{
		free(tmp[fd]);
		tmp[fd] = NULL;
		return (NULL);
	}
	res = ft_get_line(tmp[fd]);
	tmp[fd] = ft_take_rest(tmp[fd]);
	return (res);
}
/*
static int	ft_countlines(const char *s, char c);

static int	ft_putstr_fd(char *s, int fd);

int	main(void)
{
	int	fd1;
	int	fd2;
	int	i;
	char	*s = NULL;
	char	*str1 = "Numbers:\nDec:0123456789\n";
	char	*str2 = "Hex:0123456789ABCDEF\nBin:01";
	size_t	written;
	int	words;

	i = 1;
	fd1 = open("bonus1.txt", O_RDWR | O_CREAT | O_TRUNC);
	if (fd1 == -1)
		printf("Error with a file: {-1}...program should stop...\n");
	fd2 = open("bonus2.txt", O_RDWR | O_CREAT | O_TRUNC);
	if (fd2 == -1)
		printf("Error with a file: {-1}...program should stop...\n");
	written = ft_putstr_fd(str1, fd1);
	if (written != ft_strlen(str1))
		printf("Error writing to file1\n");
	written = ft_putstr_fd(str2, fd2);
	if (written != ft_strlen(str2))
		printf("Error writing to file2\n");
	words = ft_countlines(str1, '\n');
	words += ft_countlines(str2, '\n');
	lseek(fd1, 0, SEEK_SET);
	lseek(fd2, 0, SEEK_SET);
	while (words)
	{
		s = get_next_line(fd1);
		if (s == NULL)
			printf("Get_next_line returned NULL\n");
		else
			printf("Line %d:%s", i++, s);
		free(s);
		s = get_next_line(fd2);
		if (s == NULL)
			printf("Get_next_line returned NULL\n");
		else
			printf("Line %d:%s", i++, s);
		words--;
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
}*/
