# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 10:22:29 by btenzlin          #+#    #+#              #
#    Updated: 2022/02/21 14:17:12 by btenzlin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
NORM = norminette

GREEN = "\033[1;32m"
NO_COLOR = "\033[0m"

SRCS = main.c \
		ft_atoi.c \
		init.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@printf "%b" $(GREEN) "creating philo...\n\n" $(NO_COLOR)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@printf "%b" $(GREEN) "done!\n" $(NO_COLOR)

re: fclean all

clean:
	@printf "%b" $(GREEN) "removing object files...\n" $(NO_COLOR)
	@$(RM) $(OBJS)
	@printf "%b" $(GREEN) "done!\n" $(NO_COLOR)

fclean: clean
	@printf "%b" $(GREEN) "removing executable...\n" $(NO_COLOR)
	@$(RM) $(NAME)
	@printf "%b" $(GREEN) "done!\n" $(NO_COLOR)

norm:
	@$(NORM) $(SRCS) philo.h
	@printf "%b" $(GREEN) "OK!\n" $(NO_COLOR)

.PHONY: all clean fclean re norm