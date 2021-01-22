/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:46:46 by msamual           #+#    #+#             */
/*   Updated: 2021/01/22 18:53:23 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

int		main()
{
	char	*str = malloc(15);
	char	*src = "Hello90";
	int		fd = open("test.txt", O_RDWR);

	printf("fd = %d write = %d errno = %d\n", fd, ft_read(fd, str, 12), errno);
	printf("%s\n", str);
	return (0);
}
