# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msamual <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 15:13:59 by msamual           #+#    #+#              #
#    Updated: 2021/01/23 13:03:18 by msamual          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_strlen.s \
				ft_strcpy.s \
				ft_strcmp.s \
				ft_write.s \
				ft_read.s \
				ft_strdup.s

OBJS		=	$(SRCS:.s=.o)

BONUS_SRCS	=	ft_atoi_base_bonus.s \
				ft_list_push_front_bonus.s \
				ft_list_size_bonus.s \
				ft_list_sort_bonus.s \
				ft_list_remove_if_bonus.s

BONUS_OBJS	=	$(BONUS_SRCS:.s=.o)

NA			=	nasm
NA_FLAGS	=	-g -f macho64
FLAGS 		=	-Wall -Werror -Wextra
NAME		=	libasm.a
TEST		=	test
TEST_BONUS	=	test_bonus

%.o:			%.s
				$(NA) $(NA_FLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				rm -rf $(OBJS) $(BONUS_OBJS)

fclean:			clean
				rm -rf $(NAME) $(BONUS) $(TEST) $(TEST_BONUS)

re:				fclean $(NAME)

test:			$(NAME)
				gcc $(FLAGS) -L. -lasm -o $(TEST) main.c
				./$(TEST) < Makefile

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

test_bonus:		bonus
				gcc $(FLAGS) -L. -lasm -o $(TEST_BONUS) main_bonus.c
				./$(TEST_BONUS)

.PHONY:			clean fclean re test bonus test_bonus
