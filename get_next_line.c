/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:32:00 by thashimo          #+#    #+#             */
/*   Updated: 2023/11/20 13:59:24 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#define BUFFER_SIZE 2

char	*read_buff(int *ret, char *buff, char *str)
{
	int	i;
	int	l_nl;

	i = 0;
	l_nl = 0;
	while (buff[i] && 0 < *ret)
	{
		if (buff[i] == '\n')
		{
			str = ft_strnjoin(str, buff, i + 1);
			*ret = *ret - (i + 1);
			l_nl = ft_strlen(buff + i + 1);
			ft_memmove(buff, buff + i + 1, l_nl);
			ft_bzero(buff + l_nl, ft_strlen(buff + l_nl));
			return (str);
		}
		i++;
	}
	return (NULL);
}

char	*read_line(int fd, int *ret, char *buff, char *str)
{
	int	i;

	i = 0;
	*ret = read(fd, buff, BUFFER_SIZE);
	if (*ret == 0)
	{
		free(str);
		return (NULL);
	}
	while (0 < *ret)
	{
		if (ft_strchr(buff, '\n'))
		{
			return (read_buff(ret, buff, str));
		}
		else
		{
			buff[*ret] = '\0';
			str = ft_strnjoin(str, buff, ft_strlen(str) + ft_strlen(buff));
			*ret = read(fd, buff, BUFFER_SIZE);
		}
	}
	if (!ft_strchr(buff, '\n'))
		ft_bzero(buff, ft_strlen(buff));
	return (str);
}

char	*read_nextline(int fd, int *ret, char *buff, char *str)
{
	int	i;

	i = 0;
	while (0 < *ret)
	{
		if (ft_strchr(buff, '\n'))
		{
			return (read_buff(ret, buff, str));
		}
		else
		{	
			buff[*ret] = '\0';
			str = ft_strnjoin(str, buff, ft_strlen(str) + ft_strlen(buff));
			*ret = read(fd, buff, BUFFER_SIZE);
		}
	}
	if (!ft_strchr(buff, '\n'))
		ft_bzero(buff, ft_strlen(buff));
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*str;
	static int	ret;

	if (fd < 0 || read(fd, buff, 0) == -1)
		return (NULL);
	str = malloc(1);
	if (!str)
		return (NULL);
	ft_bzero(str, sizeof(str));
	if (*buff)
		return (read_nextline(fd, &ret, buff, str));
	return (read_line(fd, &ret, buff, str));
}

//#include <stdio.h>
//#include <fcntl.h>

//int	main(void)
//{
//	char *str;
//	int fd = open("test.txt", O_RDONLY);
//	//get_next_line(fd);
//	//get_next_line(fd);
//	//get_next_line(fd);
//	//get_next_line(fd);
//	//get_next_line(fd);
//	//get_next_line(fd);
//	//get_next_line(fd);
//	//get_next_line(fd);
//	//get_next_line(fd);
//	//get_next_line(fd);
//	//get_next_line(fd);
//	//get_next_line(fd);
//	//get_next_line(fd);
//	//get_next_line(fd);
//	printf("%s",get_next_line(fd));
//	printf("%s",get_next_line(fd));
//	printf("%s",get_next_line(fd));
//	printf("%s",get_next_line(fd));
//	printf("%s",get_next_line(fd));
//	printf("%s",get_next_line(fd));
//	printf("%s",get_next_line(fd));
//	printf("%s",get_next_line(fd));
//	printf("%s",get_next_line(fd));
//	printf("%s",get_next_line(fd));
//	printf("%s",get_next_line(fd));
//	printf("%s",get_next_line(fd));
//	return (0);
//}