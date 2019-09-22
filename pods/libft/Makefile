.PHONY: all clean fclean re

NAME=libft.a
CC=gcc
CFLAG=
CFLAG+= -Werror
CFLAG+= -Wextra
CFLAG+= -Wall
SRCNAME= ft_abs      \
		 ft_atoi     \
		 ft_bzero    \
		 ft_isprint \
		 ft_isnegative\
		 ft_isspace  \
		 ft_isalnum  \
		 ft_isalpha  \
		 ft_isascii  \
		 ft_isdigit  \
		 ft_lstadd   \
		 ft_lstdel   \
		 ft_lstdelone\
		 ft_lstiter  \
		 ft_lstmap   \
		 ft_lstnew   \
		 ft_memccpy\
		 ft_memchr\
		 ft_memcmp\
		 ft_memcpy\
		 ft_memdel\
		 ft_memmove\
		 ft_memset\
		 ft_putendl \
		 ft_putendl_fd \
		 ft_putchar  \
		 ft_putchar_fd\
		 ft_putnbr   \
		 ft_putnbr_fd\
		 ft_putpoint\
		 ft_putstarstr\
		 ft_putstr   \
		 ft_putstr_fd\
		 ft_sqrt     \
		 ft_strcmp  \
		 ft_strlen  \
		 ft_strrchr \
		 ft_strcpy   \
		 ft_strmap   \
		 ft_strdel   \
		 ft_strmapi  \
		 ft_strstr   \
		 ft_strncat  \
		 ft_strsub   \
		 ft_strequ   \
		 ft_strncmp  \
		 ft_strtrim  \
		 ft_striter  \
		 ft_strncpy  \
		 ft_strcat   \
		 ft_striteri \
		 ft_strnequ  \
		 ft_strchr   \
		 ft_strjoin  \
		 ft_strclr   \
		 ft_strlcat  \
		 ft_strnstr  \
		 ft_tolower  \
		 ft_toupper  \

OBJDIR=obj/
CLEANOBJDIR=OBJDIR
CLEANOBJ=OBJ
SRCDIR=src/

SRC= $(addprefix $(SRCDIR), $(addsuffix .c, $(SRCNAME)))

OBJ= $(addprefix $(OBJDIR), $(addsuffix .o, $(SRCNAME)))

INCDIR= inc/

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAG) -c $< -o $@ -I $(INCDIR)
	@(echo "_ \033[032m$@\033[00m")

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	
$(NAME): $(OBJDIR) $(OBJ)
	@ar -rc  $(NAME) $(OBJ)
	@(echo "[ \033[35m$(NAME)\033[00m ]")

clean:
	@rm -rf $(OBJ) $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
