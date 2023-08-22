# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manumart <manumart@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 15:38:55 by manumart          #+#    #+#              #
#    Updated: 2023/08/22 15:52:18 by manumart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRCS_NAME =	main.c \
			check_map.c \
			check_path.c \
			close_game.c \
			map.c \
			moves.c \
			get_next_line_utils.c \
			get_next_line.c \
			put_img.c \
			keys.c\
			check_map_2.c

CC = cc
CFLAGS = -Wall -Werror -Wextra  -g #-fsanitize=address

RM = rm -rf

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

SRC_PATH = ./

OBJ_PATH = ./objects

OBJS = $(addprefix $(OBJ_PATH)/, $(SRCS_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRCS_NAME))

all: $(NAME)


$(NAME) : $(LIBFT) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c 
	mkdir -p objects
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT):  
	make -C$(LIBFT_PATH)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re