# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhammani <yhammani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 05:00:33 by yhammani          #+#    #+#              #
#    Updated: 2022/02/20 04:01:21 by yhammani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

INC = Mandatory/so_long.h Mandatory/gnl/get_next_line.h

B_INC = Bonus/so_long_bonus.h Bonus/gnl/get_next_line.h

SRC_FILES = so_long.c map_checker.c draw.c play.c ft_printf.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c

B_SRC_FILES = so_long_bonus.c map_checker_bonus.c draw_bonus.c \
			play_bonus.c update_bonus.c ft_printf.c \
			gnl/get_next_line.c gnl/get_next_line_utils.c

SRC = $(addprefix Mandatory/, $(SRC_FILES))

B_SRC = $(addprefix Bonus/, $(B_SRC_FILES))

$(NAME): all

all: $(SRC) $(INC)
	cc $(FLAGS) $(SRC) -o so_long

	@echo " \n\
			███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗ \n\
			██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝ \n\
			███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗ \n\
			╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║ \n\
			███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝ \n\
			╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ "

bonus: $(B_SRC) $(B_INC)
	cc $(FLAGS) $(B_SRC) -o so_long_bonus

	@echo " \n\
			███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗         ██████╗  ██████╗ ███╗   ██╗██╗   ██╗███████╗ \n\
			██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝         ██╔══██╗██╔═══██╗████╗  ██║██║   ██║██╔════╝ \n\
			███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗        ██████╔╝██║   ██║██╔██╗ ██║██║   ██║███████╗ \n\
			╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║        ██╔══██╗██║   ██║██║╚██╗██║██║   ██║╚════██║ \n\
			███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝███████╗██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝███████║ \n\
			╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝╚═════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝ "

clean:
	rm -rf so_long so_long_bonus

fclean: clean

re: fclean all

.PHONY: all clean fclean bonus re