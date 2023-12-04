/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:26:19 by thashimo          #+#    #+#             */
/*   Updated: 2023/11/20 19:26:44 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*read_buff(int *ret, char *buff, char *str);
char	*read_line(int fd, int *ret, char *buff, char *str);
char	*read_nextline(int fd, int *ret, char *buff, char *str);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strnjoin(char *s1, char *s2, int n);
char	*ft_memmove(char *dst, char *src, int size);
char	*ft_bzero(char *m, int size);
char	*ft_strchr(char *s, int c);

#endif