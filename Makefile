# **************************************************************************** #
#                                   VARIABLES                                  #
# **************************************************************************** #

GREEN  = \033[0;32m
RED   = \033[0;31m
RESET = \033[0m
NAME    = cub3D
CC      = cc
CFLAGS  = -Wall -Wextra -Werror 


# Includes
INC     = -Iinclude -Ilibft -Iminilibx-linux

# Librairies externes
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

MLX_DIR     = minilibx-linux
MLX         = $(MLX_DIR)/libmlx.a

# Flags de link pour Linux
LDFLAGS     = -L$(LIBFT_DIR) -L$(MLX_DIR)
LDLIBS      = -lft -lmlx -lm -lXext -lX11

# ---------------------------------------------------------------------------- #
# Liste des sources du projet (à compléter à la main comme dans libft)
# ---------------------------------------------------------------------------- #

SRCS    = src/main.c \
		src/free.c \
		src/node.c \
		src/file.c \
		src/init.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		src/Parsing/file_to_line.c \
		src/Parsing/check_file.c \
		src/Parsing/parse_utils_1.c \
		src/Parsing/parse_utils.c \
		src/Parsing/parse_main.c \
		src/Parsing/create_map_utils.c \
		src/Parsing/create_map.c \
		src/Validation/validation.c \
		src/Validation/validation_utils.c

OBJS    = $(SRCS:.c=.o)

# **************************************************************************** #
#                                     RULES                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "$(GREEN)✅  $(NAME) built successfully!$(RESET)"

# Compilation des .o
%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Librairie Libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# MiniLibX
$(MLX):
	@make -C $(MLX_DIR)

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@echo "$(RED)🧹  Cleaned object files!$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(RED)🧹  Removed $(NAME)!$(RESET)"
re: fclean all
