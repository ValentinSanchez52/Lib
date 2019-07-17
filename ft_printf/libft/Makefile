# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 17:02:24 by vsanchez          #+#    #+#              #
#    Updated: 2019/05/25 15:50:09 by vsanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL= bash

#==============================================================================#
#                                   VARIABLES                                  #
#==============================================================================#

NAME= libft.a
CFLAGS= -Wall -Wextra -Werror
CC = gcc

#==============================================================================#
#                                  DIRECTORIES                                 #
#==============================================================================#

INC_PATH=	includes
OBJ_PATH=	objs
SRC_PATH=	srcs

#==============================================================================#
#                                     FILES                                    #
#==============================================================================#

INCS_NAMES=		get_next_line.h				\
				libft.h

SRCS_NAMES=		ft_atoi.c					\
				ft_bzero.c					\
				ft_int_max.c				\
				ft_int_min.c				\
				ft_intswap.c				\
				ft_isalnum.c				\
				ft_isalpha.c				\
				ft_isascii.c				\
				ft_isblank.c				\
				ft_iscntrl.c				\
				ft_isdigit.c				\
				ft_isgraph.c				\
				ft_islower.c				\
				ft_isprint.c				\
				ft_isspace.c				\
				ft_isupper.c				\
				ft_isxdigit.c				\
				ft_isnumchar.c				\
				ft_issign.c					\
				ft_itoa.c					\
				ft_lstadd.c					\
				ft_lstappend.c				\
				ft_lstdel.c					\
				ft_lstdelone.c				\
				ft_lstiter.c				\
				ft_lstmap.c					\
				ft_lstnew.c					\
				ft_lstputstr.c				\
				ft_memalloc.c				\
				ft_memccpy.c				\
				ft_memchr.c					\
				ft_memcmp.c					\
				ft_memcpy.c					\
				ft_memdel.c					\
				ft_memmove.c				\
				ft_memset.c					\
				ft_nb_len.c					\
				ft_putaddr.c				\
				ft_putchar.c				\
				ft_putchar_fd.c				\
				ft_putchar_nl.c				\
				ft_putendl.c				\
				ft_putendl_fd.c				\
				ft_putnbr.c					\
				ft_putnbr_fd.c				\
				ft_putstr.c					\
				ft_putstr_fd.c				\
				ft_realloc.c				\
				ft_str_to_upper_case.c		\
				ft_strcat.c					\
				ft_strchr.c					\
				ft_strclr.c					\
				ft_strcmp.c					\
				ft_strcpy.c					\
				ft_strdel.c					\
				ft_strdup.c					\
				ft_strequ.c					\
				ft_striter.c				\
				ft_striteri.c				\
				ft_strjoin.c				\
				ft_strlcat.c				\
				ft_strlen.c					\
				ft_strmap.c					\
				ft_strmapi.c				\
				ft_strncat.c				\
				ft_strncmp.c				\
				ft_strncpy.c				\
				ft_strnequ.c				\
				ft_strnew.c					\
				ft_strnstr.c				\
				ft_strrchr.c				\
				ft_strrev.c					\
				ft_strsplit.c				\
				ft_strstr.c					\
				ft_strsub.c					\
				ft_strtrim.c				\
				ft_tolower.c				\
				ft_toupper.c				\
				ft_str_is_alpha.c			\
				ft_str_is_lowercase.c		\
				ft_str_is_numeric.c			\
				ft_str_is_printable.c		\
				ft_str_is_uppercase.c		\
				ft_absolute_int.c			\
				ft_get_file_content.c		\
				ft_get_stdin_content.c		\
				ft_get_fd_content.c			\
				ft_print_error.c			\
				ft_str_to_tab.c				\
				ft_get_arg_str_tab.c		\
				ft_get_arg_in_1_str.c		\
				nb_words.c					\
				ft_strskip.c				\
				get_next_line.c

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

STR= $(BLUE)"["$(YELLOW)"LIBFT"$(BLUE)"]"
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
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf $(STR)" "$(PLUS)$(PURPLE)" "$(NAME)" generated\n"$(NRM)

.PHONY: all clean fclean
