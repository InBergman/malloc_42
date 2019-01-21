.PHONY: all clean fclean re exe norme

CXX = gcc

NAME = malloc

FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./src/

OBJ_PATH = ./obj/

INC_PATH = ./include/

SRC_NAME = malloc.c main.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))


all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
			$(CXX) $(FLAGS) $(INC) -c $< -o $@

clean:
		rm -fv $(OBJ)
			@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
		rm -fv $(NAME)

re: fclean all

norme:
		norminette $(SRC)
			norminette $(INC_PATH)*
