NAME = bank

CC =	@gcc
INCLUDE_PATH = includes
CFLAGS	= -Wall -Werror -Wextra -g -lpthread #-fsanitize=thread 
CFLAGS += $(addprefix -I , $(INCLUDE_PATH))

vpath %.h $(INCLUDE_PATH)

vpath %.c src

SRC = main.c bank.c queue.c utils.c

RM = @rm -rf

OBJ_DIR = obj

OBJ =	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "Creating $(NAME)"
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

v:	all
	@valgrind --tool=helgrind --leak-check=full --track-origins=yes -q ./$(NAME)

r:	all
	clear
	./$(NAME)

debug: all
	@gdb $(NAME)

.PHONY: all clean fclean re
