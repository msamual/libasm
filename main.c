/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:46:46 by msamual           #+#    #+#             */
/*   Updated: 2021/01/23 17:49:58 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int nb;

	if (n < 0)
	{
		nb = -n;
		ft_putchar_fd('-', 1);
	}
	else
		nb = n;
	if (nb < 10)
		ft_putchar_fd(nb + 48, 1);
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar_fd(nb % 10 + 48, 1);
	}
}

int		main()
{
	char	*str = "424242424242424242424242424242424242424242424242424242424242";
	char	*dest = malloc(1000);
	char	dst[100];
	int		fd = open("ft_strlen.s", O_RDWR);

	ft_write(1, "TEST write\n\n", 11);
	ft_write(1, "ft_write = ", 11);
	ft_write(1, str, 30);
	ft_write(1, "\nerrno = ", 9);
	ft_putnbr(errno);
	ft_write(1, "\n   write = ", 12);
	write(1, str, 30);
	ft_write(1, "\nerrno = ", 9);
	ft_putnbr(errno);
	write(1, "\n\n", 2);
	ft_write(1, "ft_write = ", 11);
	ft_write(0, str, 30);
	ft_write(1, "\nerrno = ", 9);
	ft_putnbr(errno);
	ft_write(1, "\n   write = ", 12);
	write(0, str, 30);
	ft_write(1, "\nerrno = ", 9);
	ft_putnbr(errno);

	printf("\n\nTEST ft_strlen:\n\n");
	printf("empty string:\nft_strlen = %lu\n   strlen = %lu\n\n", ft_strlen(""), strlen(""));
	printf("Hello World!:\nft_strlen = %lu\n   strlen = %lu\n\n", ft_strlen("Hello World!"), strlen("Hello World!"));
	printf("two symbol:\nft_strlen = %lu\n   strlen = %lu\n\n", ft_strlen("42"), strlen("42"));
	printf("one symbol:\nft_strlen = %lu\n   strlen = %lu\n\n", ft_strlen("5"), strlen("5"));
	printf("long string:\nft_strlen = %lu\n   strlen = %lu\n\n", ft_strlen(str), strlen(str));

	printf("TEST ft_strcpy:\n\n");
	ft_strcpy(dest, str);
	printf("long string:\nstr = %s\ndst = %s\n\n", str, dest);
	ft_strcpy(dest, "");
	printf("empty string\nstr = %s\ndst = %s\n\n", "", dest);
	ft_strcpy(dest, "hello world");
	printf("hello world:\nstr = %s\ndst = %s\n\n", "hello world", dest);
	ft_strcpy(dest, "42");
	printf("two symbols:\nstr = %s\ndst = %s\n\n", "42", dest);
	ft_strcpy(dest, "1");
	printf("one symbol:\nstr = %s\ndst = %s\n\n", "1", dest);

	printf("TEST ft_strcmp:\n\n");
	printf("ft_strcmp = %d\n   strcmp = %d\n\n", ft_strcmp(str, dest), strcmp(str, dest));
	ft_strcpy(dest, str);
	printf("ft_strcmp = %d\n   strcmp = %d\n\n", ft_strcmp(str, dest), strcmp(str, dest));
	str = "hello world";
	dest = "";
	printf("ft_strcmp = %d\n   strcmp = %d\n\n", ft_strcmp(str, dest), strcmp(str, dest));
	printf("ft_strcmp = %d\n   strcmp = %d\n\n", ft_strcmp(dest, str), strcmp(dest, str));
	str = "";
	dest = "";
	printf("ft_strcmp = %d\n   strcmp = %d\n\n", ft_strcmp(str, dest), strcmp(str, dest));
	str = "";
	dest = "hello world";
	printf("ft_strcmp = %d\n   strcmp = %d\n\n", ft_strcmp(str, dest), strcmp(str, dest));

	printf("TEST read:\n\n");
	ft_read(fd, dst, 50);
	printf("ft_read = %.50s\nerrno = %d\n", dst, errno);
	close(fd);
	fd = open("ft_strlen.s", O_RDONLY);
	read(fd, dst, 50);
	printf("   read = %.50s\nerrno = %d\n", dst, errno);
	close(fd);
	fd = open("ft_strlen.s", O_RDONLY);
	ft_read(fd, dest, 50);
	printf("ft_read = %.50s\nerrno = %d\n", dst, errno);
	close(fd);
	fd = open("ft_strlen.s", O_RDONLY);
	read(fd, dest, 50);
	printf("   read = %.50s\nerrno = %d\n", dst, errno);
	close(fd);
	ft_read(15, dest, 50);
	printf("ft_read = %.50s\nerrno = %d\n", dst, errno);
	read(15, dest, 50);
	printf("   read = %.50s\nerrno = %d\n\n\n", dst, errno);
	
	printf("TEST ft_strdup:\n\n");
	printf("ft_strdup = %s\n   strdup = %s\n", ft_strdup(""), strdup(""));
	printf("empty string:\nft_strdup = %s\n   strdup = %s\n\n", ft_strdup(""), strdup(""));
	printf("Hello World!:\nft_strdup = %s\n   strdup = %s\n\n", ft_strdup("Hello World!"), strdup("Hello World!"));
	printf("two symbol:\nft_strdup = %s\n   strdup = %s\n\n", ft_strdup("42"), strdup("42"));
	printf("one symbol:\nft_strdup = %s\n   strdup = %s\n\n", ft_strdup("5"), strdup("5"));
	printf("long string:\nft_strdup = %s\n   strdup = %s\n\n", ft_strdup(str), strdup(str));
	
	return (0);
}
