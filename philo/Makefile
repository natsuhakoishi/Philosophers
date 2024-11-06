# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 22:35:25 by yyean-wa          #+#    #+#              #
#    Updated: 2024/11/04 22:29:53 by yyean-wa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
PNAME = philo
CC = gcc
CFLAGS = -Wall -Werror -Wextra
EXFLAGS = -lpthread #-fsanitize=address
REMOVE = rm -rf

SRC = ph_main.c ph_libft.c ph_thread.c ph_utils.c ph_utils2.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(PNAME) $(EXFLAGS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(REMOVE) $(OBJS)

fclean: clean
	@$(REMOVE) $(PNAME)

re: fclean all

.PHONY: all clean fclean re

#     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#            God Bless        Never Crash
#                       _oo0oo_
#                      o8888888o
#                      88" . "88
#                      (| -_- |)
#                      0\  =  /0
#                    ___/`---'\___
#                  .' \\|     |// '.
#                 | \\|||  :  |||// |
#                | _||||| -:- |||||- |
#               |   | \\\  -  /// |   |
#               | \_|  ''\---/''  |_/ |
#               \  .-\__  '-'  ___/-. /
#             ___'. .'  /--.--\  `. .'___
#          ."" '<  `.___\_<|>_/___.' >' "".
#         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
#         \  \ `_.   \_ __\ /__ _/   .-` /  /
#     =====`-.____`.___ \_____/___.-`___.-'=====
#                       `=---='

# May the Buddha grant us peace, forever free from bugs,
# May the heavens bless our code, never crashing in the slugs.
# In a tower where we write, in the chambers where we dwell,
# Programmers craft their codes, trading skill for wine as well.

# Sober, we dwell in the vast online space,
# Drunk, we find our solace, in sleep's warm embrace.
# Day upon day, in cycles we spin,
# Year after year, as the digital dance begins.

# O, to fade within the glow of the screen's soft light,
# Rather than bow before a master’s might.
# While the wealthy ride in luxury's fine array,
# We humble coders travel by bus each day.

# They mock my madness, a folly that I bear,
# Yet I laugh at my fate, finding humor in despair.
# I see not the beauties that grace the bustling street,
# For who among them would a programmer greet?
#     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
