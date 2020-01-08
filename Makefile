ifeq ($(HOSTTYPE), )
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
NAME= libft_malloc_$(HOSTTYPE).so
CC=gcc
CFLAG=
CFLAG+= -Werror
CFLAG+= -Wextra
CFLAG+= -Wall
#CFLAG+= -fsanitize=address
SRCNAME= free			\
		 malloc			\
		 calloc			\
		 realloc		\
		 utils			\
		 show_alloc_mem	\

LIBS= ./pods/libft/libft.a

CC_LIBS= make -C ./pods/libft/;

INC_DIR_LIBS= -I ./pods/libft/inc

INC_DIR=./inc/

OBJDIR=./obj/
SRCDIR=./src/

SRC= $(addprefix $(SRCDIR), $(addsuffix .c, $(SRCNAME)))

OBJ= $(addprefix $(OBJDIR), $(addsuffix .o, $(SRCNAME)))

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(LIBS)
	@$(CC) -shared $(OBJ) $(LIBS) -o $@
	@(echo "[ \033[35m$@\033[00m ]")
	@rm -f libft_malloc.so
	@ln -s $(NAME) libft_malloc.so
		
	
$(LIBS): libs ;

libs:
	@$(CC_LIBS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAG) -c $< -o $@ -I $(INC_DIR) $(INC_DIR_LIBS)
	@(echo "\033[32m$@\033[00m")

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJ) $(OBJDIR)
	@(echo "\033[32mcleaned\033[00m")

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all re fclean clean
