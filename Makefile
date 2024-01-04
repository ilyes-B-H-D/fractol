NAME = fractol
CC = cc
SRC = main.c helpers.c helpers1.c mandelbrot.c julia.c burningship.c atod.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -O3 -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@ 

clean:
	$(RM) $(OBJ) $(OBJECT_B)
fclean: clean
	$(RM) $(OBJ)
re: fclean all

.PHONY: all clean fclean re	
