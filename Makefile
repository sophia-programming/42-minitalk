# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 12:37:17 by oaoba             #+#    #+#              #
#    Updated: 2023/06/19 12:37:17 by oaoba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#変数宣言↓
CC				= cc
CFLAGS			= -Wall -Wextra -Werror

NAME			= minitalk

SERVER			= server
CLIENT			= client

SERVER_SRCS		= server.c utils.c
CLIENT_SRCS		= client.c utils.c
				  
SERVER_BONUS	= server_bonus.c utils_bonus.c
CLIENT_BONUS	= client_bonus.c utils_bonus.c
	
SERVER_OBJS		= $(SERVER_SRCS:.c=.o)
CLIENT_OBJS		= $(CLIENT_SRCS:.c=.o)
				  
SERVER_BONUS_OBJS	= $(SERVER_BONUS:.c=.o)
CLIENT_BONUS_OBJS	= $(CLIENT_BONUS:.c=.o)
	
				  
ifdef withbonus
	SERVER_SRCS = $(SERVER_BONUS)
	SERVER_OBJS = $(SERVER_BONUS_OBJS)
	CLIENT_SRCS = $(CLIENT_BONUS)
	CLIENT_OBJS = $(CLIENT_BONUS_OBJS)
endif
	# (SRCSに追加する)

				  
#コマンド設定↓
all:			$(NAME)

$(NAME):		$(SERVER) $(CLIENT)


$(SERVER):		$(SERVER_OBJS)
				$(CC) $(CFLAGS) $(SERVER_SRCS) -o $(SERVER)


$(CLIENT):		$(CLIENT_OBJS)
				$(CC) $(CFLAGS) $(CLIENT_SRCS) -o $(CLIENT)
				
%.o	: %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				rm -f $(SERVER_OBJS) $(SERVER_BONUS_OBJS)
				rm -f $(CLIENT_OBJS) $(CLIENT_BONUS_OBJS)

fclean: 		clean
				rm -f $(SERVER) $(CLIENT)

re:				fclean all

bonus:
				make withbonus=1
	
.PHONY:			all clean fclean re bonus
