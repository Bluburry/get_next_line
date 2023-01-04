/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:41:46 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/01/04 16:29:57 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append_static(char *static_string, char *append_str)
{
	char	*str;

	if (!static_string)
	{
		str = (char *) malloc((ft_strlen(append_str) + 1) * sizeof(char));
		ft_memcpy(str, append_str, ft_strlen(append_str));
	}
	else
	{
		str = ft_strjoin(static_string, append_str);
		free(static_string);
	}
	return (str);
}

char	*search_newline(int fd, char *static_string)
{
	char	*buffer_str;
	ssize_t	size_read;

	if (static_string && ft_strrchr(static_string, '\n'))
		return (static_string);
	buffer_str = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer_str)
		return (NULL);
	size_read = BUFFER_SIZE;
	while (!ft_strrchr(static_string, '\n') && size_read == BUFFER_SIZE)
	{
		size_read = read(fd, buffer_str, BUFFER_SIZE);
		if (size_read < 0 || (!static_string && size_read == 0))
		{
			free(buffer_str);
			return (NULL);
		}
		buffer_str[size_read] = 0;
		static_string = append_static(static_string, buffer_str);
		if (!*static_string)
			break ;
	}
	free(buffer_str);
	return (static_string);
}

char	*get_string(char *static_string)
{
	char	*str;
	int		i;

	if (!ft_strrchr(static_string, '\n'))
		i = ft_strlen(static_string);
	else
	{
		i = 0;
		while (static_string[i] && static_string[i] != '\n')
			i++;
		i++;
	}
	str = (char *) malloc ((i + 1) * sizeof(char));
	ft_memcpy(str, static_string, i);
	return (str);
}

char	*alter_static(char *static_string)
{
	char	*str;
	int		i;
	int		size;

	size = ft_strlen(static_string);
	i = 0;
	while (static_string[i] && static_string[i] != '\n')
		i++;
	if (!static_string[i] || !static_string[i + 1])
	{
		free(static_string);
		return (NULL);
	}
	i++;
	str = (char *) malloc ((size - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, static_string + i, size - i);
	free(static_string);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*static_string;
	char			*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	static_string = search_newline(fd, static_string);
	if (!static_string)
		return (NULL);
	str = get_string(static_string);
	static_string = alter_static(static_string);
	return (str);
}
/*
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*prt;
	fd = open("files/test.txt", O_RDONLY);
	for (int i = 0; i < 5; i++)
	{
		prt = get_next_line(fd);
		printf("output: %s\n", prt);
		free(prt);
	}
	close(fd);
}
*/
/*
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*prt;
	fd = open("files/test2.txt", O_RDONLY);
	for (int i = 0; i < 2; i++)
	{
		prt = get_next_line(fd);
		printf("output: %s\n", prt);
		free(prt);
	}
	close(fd);
}
*/
/* 
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*prt;
	fd = open("files/empty.txt", O_RDONLY);
	prt = get_next_line(fd);
	printf("output: %s\n", prt);
	free(prt);
	close(fd);
} 
*/
/*
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*prt;
	fd = open("files/oneliner.txt", O_RDONLY);
	prt = get_next_line(fd);
	printf("output: %s\n", prt);
	free(prt);
	//prt = get_next_line(fd);
	//printf("output: %s\n", prt);
	//free(prt);
	close(fd);
} 
*/
