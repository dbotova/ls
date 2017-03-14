# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbotova <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/08 14:11:55 by dbotova           #+#    #+#              #
#    Updated: 2017/03/08 14:11:57 by dbotova          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS =	ft_ls.o 															\
		main.o 																\
		./util/create_cont.o 												\
		./util/dirent_to_array.o 											\
		./util/get_path.o 													\
		./util/has_option.o 												\
		./util/listfiles.o 													\
		./util/long_format.o 												\
		./util/sort_by_name.o 												\
		./util/sort_by_name_rev.o 											\
		./util/sort_dirent_arr.o 											\
		./util/sort_dirent_arr_rev.o 										\
		./util/sort_dirent_arr_c.o 											\
		./util/sort_dirent_arr_rev_c.o 										\
		./util/sort_dirent_arr_u.o 											\
		./util/sort_dirent_arr_rev_u.o 										\
		./util/take_args.o 													\
		./util/free_cont.o
LIBS = ./libft.a

HEADERS = ft_ls.h ./libft/libft.h

CFLAGS += -Wall -Werror -Wextra

NAME = ft_ls

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ): $(HEADERS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all