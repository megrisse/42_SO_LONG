
NAME = so_long

CC = gcc

FLAGS = -W -W -W -lmlx -O3 -framework OpenGL -framework Appkit

HEADER = ./gnl/get_next_line.h ./libft/libft.h ./ft_printf/ft_printf.h so_long.h

SRC =	steps.c gametime.c inputs.c draw.c check.c exit.c so_long.c last.c Libft/ft_bzero.c	\
		Libft/ft_calloc.c Libft/ft_memcpy.c Libft/ft_memset.c Libft/ft_split.c Libft/ft_strdup.c Libft/ft_strjoin.c	 \
		Libft/ft_strlen.c Libft/ft_substr.c GNL/get_next_line.c GNL/get_next_line_utils.c \
		ft_printf/ft_printf.c ft_printf/printf_tool.c ft_printf/printf_tool1.c \

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean :
		rm -rf $(OBJ)

fclean :
		rm -rf $(NAME)

re : fclean all
		
.PHONY	: all clean fclean re	



