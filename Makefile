# **************************************************************************** #
#                                   VARIABLES                                  #
# **************************************************************************** #

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
		src/Parsing/check_map.c

OBJS    = $(SRCS:.c=.o)

# **************************************************************************** #
#                                     RULES                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

# Compilation des .o
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Librairie Libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# MiniLibX
$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
