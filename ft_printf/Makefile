# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 17:02:24 by vsanchez          #+#    #+#              #
#    Updated: 2019/05/16 17:44:53 by vsanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL= bash

#==============================================================================#
#                                   VARIABLES                                  #
#==============================================================================#

NAME=				libftprintf.a
LIB_NAME=			libft.a
CFLAGS=				-Wall -Wextra -Werror
CC =				gcc

#==============================================================================#
#                                  DIRECTORIES                                 #
#==============================================================================#
LIB_PATH=			libft
INC_PATH=			includes
OBJ_PATH=			objs
SRC_PATH=			srcs

#==============================================================================#
#                                     FILES                                    #
#==============================================================================#

LIB_INCS_NAMES=		get_next_line.h				\
					libft.h

INCS_NAMES=			ft_printf.h

LIB_SRCS_NAMES=		ft_atoi.c					\
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

SRCS_NAMES=			ft_add_a_plus.c				\
					ft_add_a_prefix.c			\
					ft_add_a_space.c			\
					ft_bigx_conv.c				\
					ft_c_conv.c					\
					ft_d_conv.c					\
					ft_f_conv.c					\
					ft_find_attributes.c		\
					ft_itoa_base.c				\
					ft_lltoa.c					\
					ft_ltoa.c					\
					ft_make_str.c				\
					ft_o_conv.c					\
					ft_p_conv.c					\
					ft_percent_conv.c			\
					ft_printf.c					\
					ft_s_conv.c					\
					ft_u_conv.c					\
					ft_ulltoa.c					\
					ft_vsprintf.c				\
					ft_x_conv.c					\
					replace_by_str.c			\
					utilities.c					\
					zero_filled.c

OBJS_NAMES= $(SRCS_NAMES:.c=.o)
LIB_OBJS_NAMES= $(LIB_SRCS_NAMES:.c=.o)

SRCS= $(addprefix $(SRC_PATH)/,$(LIB_SRCS_NAMES))
OBJS= $(addprefix $(OBJ_PATH)/,$(OBJS_NAMES))
INCS= $(addprefix $(INC_PATH)/,$(INCS_NAMES))
LIB_INCS= $(addprefix $(LIB_PATH)/,$(addprefix $(INC_PATH)/,$(LIB_INCS_NAMES)))
LIB_OBJS= $(addprefix $(LIB_PATH)/,$(addprefix $(OBJ_PATH)/,$(LIB_OBJS_NAMES)))

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

STR= $(BLUE)"["$(YELLOW)"FT_PRINTF"$(BLUE)"]"
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
	@make -C $(LIB_PATH) fclean
	@rm -f $(NAME)
	@printf $(STR)" "$(LESS)$(PURPLE)" "$(NAME)" fcleaned\n"$(NRM)

re: fclean all

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCS) $(LIB_PATH)/$(LIB_NAME)
	@mkdir -p $(OBJ_PATH)
	@$(CC) -o $@ $(CFLAGS) -I$(INC_PATH) -c $<; \
		if [ "$$?" != "1" ]; then \
			printf $(STR)" "$(PLUS)" "$(NRM)$<"\n"; exit 0; \
		else \
			printf $(STR)" "$(WARN)" "$(NRM)$<"\n"; exit 2; \
		fi

$(NAME): $(OBJS) $(INCS) $(LIB_PATH)/$(LIB_NAME)
	@ar rc $(NAME) $(OBJS) $(LIB_OBJS)
	@ranlib $(NAME)
	@printf $(STR)" "$(PLUS)$(PURPLE)" "$(NAME)" generated\n"$(NRM)

$(LIB_PATH)/$(LIB_NAME): FORCE
	@make -C $(LIB_PATH)

FORCE:

.PHONY: all clean fclean FORCE
