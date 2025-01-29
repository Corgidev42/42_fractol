# Compiler et flags
CC = gcc
CFLAGS =

# Nom du projet à définir pour chaque projet
PROJECT_NAME = 42_fractol

# Include path (répertoire contenant les fichiers headers du projet)
INCLUDES = -I/Users/dev/Documents/Workspace/C/$(PROJECT_NAME)/include

# Library path for libft.a (chemin vers libft.a)
LIBFT_DIR = /Users/dev/Documents/Workspace/C/mylib/lib
LIBFT = -L$(LIBFT_DIR) -lft

# Library path for libmlx.dylib
LIBMLX_DIR = /Users/dev/Documents/Workspace/C/$(PROJECT_NAME)/lib

# Répertoire source du projet
SRC_DIR = ./src
OBJ_DIR = ./obj

# Trouver tous les fichiers .c dans le répertoire src/
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Exclure test.c de la liste des fichiers sources pour la compilation principale
SRC_FILES_EXCLUDE_TEST = $(filter-out $(SRC_DIR)/test.c, $(SRC_FILES))

# Fichiers objets à partir des fichiers .c du projet (sauf test.c)
OBJ_FILES = $(SRC_FILES_EXCLUDE_TEST:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default target : compile le projet principal
all: $(OBJ_DIR) $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(CFLAGS) $(INCLUDES) $(LIBFT) -L$(LIBMLX_DIR) -Wl,-rpath,$(LIBMLX_DIR) -lmlx -o $(PROJECT_NAME)

# Exécuter le programme avec la bibliothèque libmlx.dylib
run: all
	DYLD_LIBRARY_PATH=/Users/dev/Documents/Workspace/C/$(PROJECT_NAME)/lib  ./$(PROJECT_NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

# Règle pour compiler les fichiers sources .c en fichiers objets .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

# Règle pour générer et exécuter les tests
test: $(SRC_DIR)/test.c $(OBJ_FILES)
	@if [ -f $(SRC_DIR)/test.c ]; then \
		$(CC) $(CFLAGS) $(INCLUDES) $(SRC_DIR)/test.c $(OBJ_FILES) $(LIBFT) $(LIBMLX) -o test_runner; \
		./test_runner; \
	else \
		echo "Please rename your generated test file to 'test.c' and place it here."; \
		echo "Then run 'make test' to execute the tests."; \
	fi

# Nettoyage des fichiers objets uniquement
clean:
	rm -rf $(OBJ_DIR)
	@echo "Cleaned object files."

# Nettoyage complet : objets, exécutable principal et fichiers de test
fclean: clean
	rm -f $(PROJECT_NAME) test_runner
	@echo "Fully cleaned: removed executables and test binaries."

# Reconstruire tout (objets, exécutable principal, puis tests)
re: fclean all
	@echo "Rebuilt everything."

