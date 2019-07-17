# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 17:02:24 by vsanchez          #+#    #+#              #
#    Updated: 2019/07/17 12:17:58 by vsanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL= bash

#==============================================================================#
#                                   VARIABLES                                  #
#==============================================================================#

NAME=			project
CFLAGS=			-Wall -Wextra -Werror
CC =			gcc

#==============================================================================#
#                                  DIRECTORIES                                 #
#==============================================================================#

INC_PATH=		includes
OBJ_PATH=		objs
SRC_PATH=		srcs
LIB_PATH=		ft_printf

#==============================================================================#
#                                     FILES                                    #
#==============================================================================#

INCS_NAMES=		project.h

SRCS_NAMES=		project.c

OBJS_NAMES= $(SRCS_NAMES:.c=.o)

SRCS= $(addprefix $(SRC_PATH)/,$(SRCS_NAMES))
OBJS= $(addprefix $(OBJ_PATH)/,$(OBJS_NAMES))
INCS= $(addprefix $(INC_PATH)/,$(INCS_NAMES))

#==============================================================================#
#                                    COLORS                                    #
#==============================================================================#

NRM= "\e[0m"
BLACK= "\e[30m"
RED= "\e[31m"
GREEN= "\e[32m"
YELLOW= "\e[33m"
BLUE= "\e[34m"
PURPLE= "\e[35m"
CYAN= "\e[36m"
GREY= "\e[37m"
ORANGE= "\e[38;5;266m"

#==============================================================================#
#                                    STRINGS                                   #
#==============================================================================#

STR= $(BLUE)"["$(YELLOW)"PUSH_SWAP"$(BLUE)"]"
PLUS= "["$(GREEN)" + "$(BLUE)"]"
LESS= "["$(RED)" - "$(BLUE)"]"
WARN= "["$(ORANGE)" ! "$(BLUE)"]"

#==============================================================================#
#                                     RULES                                    #
#==============================================================================#

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_PATH)
	@printf $(STR)" "$(LESS)$(PURPLE)" "$(NAME)" cleaned\n"$(NRM)

fclean: clean
	@rm -f $(NAME)
	@printf $(STR)" "$(LESS)$(PURPLE)" "$(NAME)" fcleaned\n"$(NRM)

re: fclean all

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCS)
	@mkdir -p $(OBJ_PATH)
	@$(CC) -o $@ $(CFLAGS) -I$(INC_PATH) -c $<; \
		if [ "$$?" != "1" ]; then \
			printf $(STR)" "$(PLUS)" "$(NRM)$<"\n"; exit 0; \
		else \
			printf $(STR)" "$(WARN)" "$(NRM)$<"\n"; exit 2; \
		fi

$(NAME): $(OBJS) $(INCS)
	@$(CC) $(OBJS) -o $@ $(CFLAGS) -I$(INC_PATH) -I$(LIB_PATH) \
		$(LIB_PATH)/libftprintf.a
	@printf $(STR)" "$(PLUS)$(PURPLE)" "$(NAME)" generated\n"$(NRM)

.PHONY: all clean fclean
