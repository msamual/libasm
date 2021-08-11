/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:09:09 by msamual           #+#    #+#             */
/*   Updated: 2021/01/22 19:01:02 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <errno.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;


unsigned long	ft_strlen(char *str);
char			*ft_strcpy(char *dst, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_write(int fildes, const void *buf, int nbyte);
int				ft_read(int fildes, const void *buf, int nbyte);
char			*ft_strdup(const char *src);

int				ft_atoi_base(char *str, int base);
void			ft_list_push_front(t_list **begin_list, void *data);
int				ft_list_size(t_list *begin_list);
void			ft_list_sort(t_list **begin_list, int (*cmp)());
void			ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

#endif
