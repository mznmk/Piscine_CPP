# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 16:58:27 by mmizuno           #+#    #+#              #
#    Updated: 2021/07/29 23:45:35 by mmizuno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================= Variable ================================= #

NAME				= megaphone

INC_DIR				= ./source/
SRC_DIR				= ./source/
SRC_NAME			= megaphone.cpp
SRCS				= $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJS				= $(SRCS:.cpp=.o)					  

CC					= clang++
CFLAGS				= -Wall -Wextra -Werror
INCDIR				= -I $(INC_DIR)

RM					= rm -f

# ----------------------------- Escape Character ----------------------------- #

ESC_RESET			= \033[0m
ESC_FNT_BOLD		= \033[1m
ESC_FNT_FINE		= \033[2m
ESC_FNT_ITALIC		= \033[3m
ESC_FNT_ULINE		= \033[4m
ESC_CLR_BLACK		= \033[38;5;00m
ESC_CLR_RED			= \033[38;5;01m
ESC_CLR_GREEN		= \033[38;5;02m
ESC_CLR_YELLOW		= \033[38;5;03m
ESC_CLR_BLUE		= \033[38;5;04m
ESC_CLR_MAGENTA		= \033[38;5;05m
ESC_CLR_CYAN		= \033[38;5;06m
ESC_CLR_WHITE		= \033[38;5;07m

# ================================== Rules =================================== #

# ---------------------------------- .c.o ------------------------------------ #

.cpp.o:
					$(CC) $(CFLAGS) $(INCDIR) -c $< -o $(<:.cpp=.o)

# --------------------------------- $(NAME) ---------------------------------- #

$(NAME):			$(OBJS)
					@echo "$(ESC_FNT_BOLD)$(ESC_CLR_CYAN)[ $(NAME) is compiling ... ]$(ESC_RESET)"
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
					@echo "$(ESC_FNT_BOLD)$(ESC_CLR_YELLOW)[ $(NAME) successfully compiled !! ]$(ESC_RESET)"

# ----------------------------------- all ------------------------------------ #

all:				$(NAME)

# ---------------------------------- clean ----------------------------------- #

clean:
					$(RM) $(OBJS)

# ---------------------------------- fclean ---------------------------------- #

fclean:				clean
					$(RM) $(NAME)

# ------------------------------------ re ------------------------------------ #

re:					fclean all

# ----------------------------------- test ----------------------------------- #

test:
					@echo "$(ESC_FNT_BOLD)$(ESC_CLR_CYAN)[ start test !! ]$(ESC_RESET)"
					./$(NAME) "shhhhh... I think the students are asleep..."
					./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
					./$(NAME)
					@echo "$(ESC_FNT_BOLD)$(ESC_CLR_YELLOW)[ finish test !! ]$(ESC_RESET)"

# ---------------------------------- .PHONY ---------------------------------- #

.PHONY:				all clean fclean re test

# ============================================================================ #
