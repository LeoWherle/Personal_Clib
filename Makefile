##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME = ooc

CYAN		=	'\033[1;36m'
BLUE		=	'\033[1;34m'
GREEN 		= 	'\033[1;32m'
RED			=	'\033[1;31m'

RESET		=	'\033[0m'

SRC = $(MATRIX)

MATRIX =	matrix/matrix_basics.c	\
			matrix/matrix_core.c	\
			matrix/matrix_editor.c	\
			matrix/matrix_init.c	\
			matrix/matrix_op_methods.c \
			matrix/matrix_operations.c	\
			matrix/matrix_printer.c	\
#			matrix/matrix_main_test.c	\

CFLAGS = -W -Wall -Wextra -I./includes

OBJ						:=	$(SRC:%.c=%.o)
# ----------------------------------------------------------------------------

%.o: %.c
	@$(CC) $(CFLAGS) $^ -c -o $@
	@echo -e $(BLUE)'[builded]'$(RESET)': $(notdir $^) -> $(notdir $@)'

$(NAME) : RULE = $(NAME)
$(NAME): $(OBJ)
		@gcc -o $(NAME) $(OBJ)
		@echo -e $(GREEN)'[finished]'$(RESET)': $(NAME): $(RULE)'

all: $(NAME)
	@echo -e $(GREEN)'[finished]'$(RESET)': $(NAME): $(RULE)'

clean: RULE = clean
clean:
	@rm -f
	@rm -f $(OBJ)
	@echo -e $(GREEN)'[finished]'$(RESET)': $(NAME): $(RULE)'

fclean:	RULE = fclean
fclean:	clean
	@rm -f $(NAME)
	@echo -e $(GREEN)'[finished]'$(RESET)': $(NAME): $(RULE)'

vclean:	RULE = vclean
vclean: fclean
	@rm -f vgcore.* coding-style-reports.log
	@echo -e $(GREEN)'[finished]'$(RESET)': $(NAME): $(RULE)'

re: RULE = re
re:	fclean all
	@echo -e $(GREEN)'[finished]'$(RESET)': $(NAME): $(RULE)'

.PHONY: all clean fclean vclean re