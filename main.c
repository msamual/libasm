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
	char *src = "\xff\xff";
	char *str = "\xff";
	printf("cmp = %zd\n", ft_strcmp(src, str));
	return (0);
}
