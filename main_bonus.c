/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:18:04 by msamual           #+#    #+#             */
/*   Updated: 2021/01/26 19:18:07 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

void	test_bonus(char **av)
{
	t_list	*lst = NULL;
	t_list	*lst1;
	int		i = 0;

	if (!av)
		return	;
	while (av[i])
		ft_list_push_front(&lst, av[i++]);
	lst1 = lst;
	printf("size = %d\n", ft_list_size(lst));
	while (lst)
	{
		printf("data = %s\n", lst->data);
		lst = lst->next;
	}
	lst = lst1;
	ft_list_sort(&lst, ft_strcmp);
	printf("\nsorted:\n");
	while (lst)
	{
		printf("data = %s\n", lst->data);
		lst = lst->next;
	}
	ft_list_remove_if(&lst1, "test3", ft_strcmp);
	printf("\nremove \"test3\":\n");
	while (lst1)
	{
		printf("data = %s\n", lst1->data);
		lst1 = lst1->next;
	}
}

int		main()
{
	char	**test_case = malloc(sizeof(char *) * 20);

	test_case[0] = "test1";
	test_case[1] = "test2";
	test_case[2] = "test3";
	test_case[3] = "test4";
	test_case[4] = "test5";
	test_case[5] = "test6";
	test_case[6] = "test7";
	test_case[7] = NULL;
	test_bonus(test_case);

	test_case[0] = "test3";
	test_case[1] = "test3";
	test_case[2] = "test3";
	test_case[3] = "test3";
	test_case[4] = "test3";
	test_case[5] = "test3";
	test_case[6] = "test3";
	test_case[7] = NULL;
	test_bonus(test_case);

	test_case[0] = "test3";
	test_case[1] = "test2";
	test_case[2] = "test3";
	test_case[3] = "test4";
	test_case[4] = "test5";
	test_case[5] = "test6";
	test_case[6] = "test3";
	test_case[7] = NULL;
	test_bonus(test_case);

	test_case[0] = "test1";
	test_case[1] = NULL;
	test_case[2] = "test3";
	test_case[3] = "test4";
	test_case[4] = "test5";
	test_case[5] = "test6";
	test_case[6] = "test7";
	test_case[7] = NULL;
	test_bonus(test_case);

	test_case[0] = NULL;
	test_case[1] = "test2";
	test_case[2] = "test3";
	test_case[3] = "test4";
	test_case[4] = "test5";
	test_case[5] = "test6";
	test_case[6] = "test7";
	test_case[7] = NULL;
	test_bonus(test_case);

	return (0);
}