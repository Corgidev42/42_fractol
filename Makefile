# Compiler et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Nom du projet
PROJECT_NAME = fractol

# Détection de l'OS
UNAME_S := $(shell uname -s)

# Configuration spécifique à l'OS
ifeq ($(UNAME_S), Linux)
	MLX_DIR = minilibx-linux
	MLX = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -lXext -lX11 -lm
else ifeq ($(UNAME_S), Darwin)
	MLX_DIR = minilibx-mac-2
	MLX = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -framework OpenGL -framework AppKit -I /opt/X11/include/X11
endif

# Include path (répertoire contenant les fichiers headers du projet)
INCLUDES = -I ./include

# Library path for libft.a (chemin vers libft.a)
LIBFT_DIR = mylib
LIBFT = $(LIBFT_DIR)/lib/libft.a

# Répertoire source du projet
SRC_DIR = ./src

# Trouver tous les fichiers .c dans le répertoire src/
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Répertoire où seront stockés les fichiers objets
OBJ_DIR = obj

# Liste des fichiers objets (transformation des .c en .o dans obj/)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Default target : compile le projet principal
all: $(PROJECT_NAME)

# Création de l'exécutable
$(PROJECT_NAME): $(LIBFT) $(MLX) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_FILES) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $@

# Règle pour compiler les fichiers sources .c en fichiers objets .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

# Création du répertoire obj s'il n'existe pas
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compilation de la MinilibX et de la Libft
$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

# Nettoyage des fichiers objets uniquement
clean:
	rm -rf $(OBJ_DIR)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean
	@echo "Cleaned object files."

# Nettoyage complet : objets, exécutable principal et fichiers de test
fclean: clean
	rm -f $(PROJECT_NAME)
	make -C $(LIBFT_DIR) fclean
	@echo "Fully cleaned: removed executables and test binaries."

# Reconstruire tout (objets, exécutable principal, puis tests)
re: fclean all
	@echo "Rebuilt everything."
