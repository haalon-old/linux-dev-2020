NAME = hist

CC = gcc

# note that '-fopenmp' is a flag and not a library
FLAGS = -Wall

LIBRARIES = -lm $(shell pkg-config --libs glib-2.0)
INCLUDES = -I. $(shell pkg-config --cflags glib-2.0)

HEADERS = 
SOURCES = hist.c

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(SOURCES:.c=.o)
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re


$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo -e "$(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo -e "$(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o: %.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo -e "$(GREEN)\t" $@ " was created$(RESET)"

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo -e "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo -e "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

