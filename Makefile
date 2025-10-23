NAME = push_swap
INC_DIR = includes
OBJ_DIR = obj
SRC_DIR = src
LIBFT_DIR = libft

PUSH_ALGORITHM = \
				all_cases.c \
				push_utils.c \
				utils_stack.c \
				optmization_a.c

PUSH_INSTRUCTIONS = \
					push.c \
					reverse_rotate.c \
					rotate.c \
					swap.c

PUSH_VALIDATIONS = \
					ft_check_duplicates.c \
					ft_is_int.c \
					ft_only_number.c \
					mensage_error.c \
					numbers_valid.c \
					utils_struct.c

MAIN = push_swap.c

SRCS = \
		$(addprefix $(SRC_DIR)/push_algorithm/, $(PUSH_ALGORITHM)) \
		$(addprefix $(SRC_DIR)/push_instructions/, $(PUSH_INSTRUCTIONS)) \
		$(addprefix $(SRC_DIR)/push_validations/, $(PUSH_VALIDATIONS)) \
		$(addprefix $(SRC_DIR)/main/, $(MAIN))


LIBFT = $(LIBFT_DIR)/libft.a
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)/includes

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "✅ Build complete: $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -sC $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -sC $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -sC $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
