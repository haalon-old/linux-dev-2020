NAME = unlinkat.so

cc = gcc
FLAGS = -shared -fPIC
LIBRARIES = -ldl

SRC = unlinkat.c

RED = \e[31m
GREEN = \e[32m
RS = \e[0m

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(FLAGS) $(LIBRARIES) $(SRC) -o $(NAME)
	@echo -e "$(GREEN)$(NAME) was created$(RS)"

FNAME1 = "what is love"
FNAME2 = "baby dont FIX me, dont FIX me, no more"

test: $(NAME)
	@touch $(FNAME1)
	@touch $(FNAME2)
	@LD_PRELOAD=$(shell pwd)/$(NAME) rm $(FNAME1)
	@LD_PRELOAD=$(shell pwd)/$(NAME) rm $(FNAME2)
	@test -f $(FNAME1) && echo -e "$(RED)FAIL! File $(RS)'$(FNAME1)'$(RED) was not deleted$(RS)" || \
	    echo -e "$(GREEN)SUCCESS! File $(RS)'$(FNAME1)'$(GREEN) was deleted$(RS)"
	@test -f $(FNAME2) && echo -e "$(GREEN)SUCCESS! File $(RS)'$(FNAME2)'$(GREEN) was not deleted$(RS)" || \
	    echo -e "$(RED)FAIL! File $(RS)'$(FNAME2)'$(RED) was deleted$(RS)"
	@[ ! -e $(FNAME1) ] || rm $(FNAME1)
	@[ ! -e $(FNAME2) ] || rm $(FNAME2)

clean:
	rm -rf *.so