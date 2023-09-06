# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/02 08:37:28 by emaksimo          #+#    #+#              #
#    Updated: 2023/09/06 06:13:40 by emaksimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

LIBFTD = libft/
INCD = include/
SRSD = srcs/
OBJD = objects/
BONUSD = bonus/
BONUSSD = ${BONUSD}srcs/
BONUSOD = ${BONUSD}objects/

LIBFT := ${addprefix ${LIBFTD},libft.a}
SOURCES = push_swap.c basic_sort.c command.c command_utils.c push.c stacks_utils.c \
principal_nodes.c reverse_rotate_swap.c sort_utils.c stacks.c utils.c valid.c
BONUS = checker.c gnl_push_swap.c gnl_utils.c

OBJECTS := ${addprefix ${OBJD},${SOURCES:.c=.o}}
BONUSO	:= ${addprefix ${BONUSOD},${BONUS:.c=.o}}

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFTMK = make -C $(LIBFTD)

BLUE = \033[1;36m 
PINK = \033[1;35m
RESET = \033[0m

WHALE	=	"\n$(BLUE)       ::: \n     ___:____     |^\/^| \n   ,'        '.    \  / \n   |  O        \___/  | \n ~^~^~^~^~^~^~^~^~^~^~^~^~\n \n Compilation Successful!	${NC}\n"
NUKE	=	"\n$(PINK)    _.-^^---....,,--       \n _--                  --_  \n<                        >)\n|                         | \n \._                   _./  \n    '''--. . , ; .--'''       \n          | |   |             \n       .-=||  | |=-.   \n       '-=£€%&%€£=-'   \n          | ;  :|     \n _____.,-£%&€@%£&£~,._____${NC}\n\n"


.PHONY: all test clean fclean re 


all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS) $(INCD)push_swap.h
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -I$(INCD) -o $(NAME) 
	@echo "\n$(NAME): $(BLUE) Making Libft... $(RESET)"
	@echo "\n$(NAME): $(BLUE) Making push_swap... $(RESET)"
	@echo $(WHALE)
	

$(OBJD)%.o: $(SRSD)%.c
	mkdir -p $(OBJD)
	$(CC) -c -o $@ $(CFLAGS) -I$(INCD) -I$(LIBFTD) $?



$(LIBFT):
	$(LIBFTMK)

bonus: $(LIBFT) $(BONUSO) $(INCD)push_swap.h $(INCD)checker.h $(INCD)get_next_line_ps.h 
	$(CC) $(CFLAGS) $(BONUSO) ${filter-out ${OBJD}push_swap.o,${OBJECTS}} $(LIBFT) -o $(BONUS_NAME) 
	@echo "\n$(NAME_2) $(BLUE) Making checker... $(RESET)"
	@echo $(WHALE)

   
$(BONUSOD)%.o: $(BONUSSD)%.c
	mkdir -p $(BONUSOD)
	$(CC) -c -o $@ $(CFLAGS) -I$(INCD) -I$(LIBFTD) $?

test: bash tester/tester.sh push_swap $(ARGS)
	
clean:  
	-rm -rf $(OBJD) $(BONUSOD)
	$(LIBFTMK) clean
	@echo "$(PINK) clean libft  $(RESET)"
	@echo "$(PINK) clean checker $(RESET)"
	@echo "$(PINK) clean push_swap $(RESET)"

fclean: clean
	-rm $(NAME) $(BONUS_NAME)
	$(LIBFTMK) fclean
	@echo "$(PINK) fclean libft $(RESET)"
	@echo "$(PINK) fclean checker $(RESET)"
	@echo "$(PINK) fclean push_swap $(RESET)"
	@echo "$(PINK) ...3 2 1 $(RESET)"
	@echo $(NUKE)

re: fclean all