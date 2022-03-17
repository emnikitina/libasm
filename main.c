/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odomenic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:27:07 by odomenic          #+#    #+#             */
/*   Updated: 2021/04/03 17:48:40 by odomenic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


void	test_strlen(char *str)
{
	printf("string: |%s|\n", str);
	printf("my strlen: %zu\n", ft_strlen(str));
	printf(" original: %zu\n\n",  strlen(str));
}

void	test_strcpy(char *src)
{
	char *dst;

	printf("string for copy: %s\n", src);
	if (!(dst = (char *)malloc(sizeof(char) * (strlen(src) + 1))))
		printf("malloc error\n");
	printf("      my strcpy: %s\n", ft_strcpy(dst, src));
	free(dst);
	if (!(dst = (char *)malloc(sizeof(char) * (strlen(src) + 1))))
		printf("malloc error\n");
	printf("original strcpy: %s\n\n",  strcpy(dst, src));
	free(dst);
}

void	test_strcmp(char *str1, char *str2)
{
	printf("String for comparison:\ns1: %s\ns2: %s\n", str1, str2);
	printf("  my cmp: %d\n", ft_strcmp(str1, str2));
	printf("original: %d\n\n",  strcmp(str1, str2));
}

void	test_write(char *str, int fd1, int fd2)
{
	printf("      my write: %zd\n", ft_write(fd1, str, strlen(str)));
	printf("      my errno: %d\n", errno);
	printf("original write: %zd\n",    write(fd2, str, strlen(str)));
	printf("original errno: %d\n\n", errno);
}

void	test_read(int len)
{
	int		fd;
	char	*buf;

	if (!(buf = (char *)malloc(sizeof(char) * len)))
		printf("malloc error\n");
	if ((fd = open("test1.txt", O_RDWR)) == -1)
		printf("Can't open file for read and write\n");
	printf(" my read: %zd\nbuf: %s\n", ft_read(fd, buf, len), buf);
	close(fd);
	free(buf);
	if (!(buf = (char *)malloc(sizeof(char) * len)))
		printf("malloc error\n");	
	if ((fd = open("test2.txt", O_RDWR)) == -1)
		printf("Can't open file for read and write\n");
	printf("original: %zd\n",  read(fd, buf, len));
	printf("buf: %s\n\n", buf);
	close(fd);
	free(buf);
}

void	test_strdup(char *str)
{
	char *ret_str;

	ret_str = ft_strdup(str);
	printf("my strdup: |%s|\n", ret_str);
	free(ret_str);
	ret_str = strdup(str);
	printf(" original: |%s|\n\n", ret_str);
	free(ret_str);
}

int	main()
{
	int fd1;
	int	fd2;
	
	printf("----------Test ft_strlen----------\n");
	test_strlen("The 1st string!");
	test_strlen("");
	test_strlen("Veeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeery long string");

	printf("----------Test strcpy----------\n");
	test_strcpy("string");
	test_strcpy("");
	test_strcpy("interesting string\nschool21\n\n 1111 end");

	printf("----------Test strcmp----------\n");
	test_strcmp("", "");
	test_strcmp("hello", "hello");
	test_strcmp("hello1", "hello");
	test_strcmp("hello", "hello5");
	test_strcmp("Aqwerty", "Azxcvbn");
	test_strcmp("dddd", "jjj");

	printf("----------Test write----------\n");
	if ((fd1 = open("test1.txt", O_RDWR)) == -1)
		printf("Can't open file for read and write\n");
	if ((fd2 = open("test2.txt", O_RDWR)) == -1)
		printf("Can't open file for read and write\n");
	test_write("The 1st string to file!", fd1, fd2);
	test_write("", fd1, fd2);
	test_write("simple string", -2, -2);
	close(fd1);
	close(fd2);

	printf("-----------Test read-----------\n");
	test_read(0);
	test_read(10);
	test_read(15);

	printf("----------Test strdup----------\n");
	test_strdup("");
	test_strdup("simple string");
	test_strdup("loooooooong\n\nstring!111 :)");

	return (0);
}
