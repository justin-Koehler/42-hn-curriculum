# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/12 18:20:00 by jukohler          #+#    #+#              #
#    Updated: 2026/06/12 19:03:55 by jukohler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := push_swap

CC          := cc
CFLAGS      := -Wall -Wextra -Werror -I. -ILibft -Ift_printf

LIBFT_DIR   := Libft
LIBFT       := $(LIBFT_DIR)/libft.a

PRINTF_DIR  := ft_printf
PRINTF      := $(PRINTF_DIR)/libftprintf.a

SRCS        := main.c \
               parser.c \
               utils.c \
               operations.c \
               instructions.c \
               sort.c

OBJS        := $(SRCS:.c=.o)

GREEN       := \033[1;32m
RESET       := \033[0m

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@cc $(CFLAGS) -c $(PRINTF_DIR)/*.c
	@mv *.o $(PRINTF_DIR)/
	@ar rcs $(PRINTF) $(PRINTF_DIR)/*.o
	@echo "$(GREEN)[ft_printf] Bibliothek erfolgreich gebaut!$(RESET)"

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) main.c parser.c utils.c operations.c instructions.c sort.c $(PRINTF_DIR)/*.c $(LIBFT_DIR)/ft_putchar_fd.c $(LIBFT_DIR)/ft_itoa.c $(LIBFT_DIR)/ft_strlen.c $(LIBFT) -o $(NAME)
	@echo "$(GREEN)[push_swap] Binärdatei erfolgreich erstellt!$(RESET)"

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(PRINTF_DIR)/*.o $(OBJS)
	@echo "[push_swap] Objektdateien vollständig bereinigt."

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(PRINTF) $(NAME)
	@echo "[push_swap] Binärdateien und Bibliotheken gelöscht."

re: fclean all

.PHONY: all clean fclean re
