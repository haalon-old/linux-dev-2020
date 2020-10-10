GENERATES = prog README prog-a prog-b libout*
TRASH = *.o *~ o.* *.temp
CFLAGS= -Wall -fPIC

all:    README prog

prog:   const.o fun.o prog.o

prog-a: prog.o libouta.a
	cc -L. prog.o -louta -o $@

prog-b: prog.o liboutb.so
	cc -L. prog.o -loutb -o $@

libouta.a: const.o fun.o
	ar -rcs $@ $^

liboutb.so: const.o fun.o
	cc -shared $^ -o $@

README: prog
	./$< 2> $@

fun.o:  outlib.h

clean:
	rm -f $(TRASH)

distclean:      clean
	rm -rf $(GENERATES)

RED = \e[31m
GREEN = \e[32m
RS = \e[0m

tests: test0 test1 test2 clean

test0: prog prog-a prog-b
	./prog 2> test.temp
	./prog-a 2> test-a.temp
	LD_LIBRARY_PATH=`pwd` ./prog-b 2> test-b.temp
	echo -e "$(GREEN)SUCCESS$(RS) (because they are different anyway)" 

test1: prog prog-a prog-b
	./prog one > test.temp
	./prog-a one > test-a.temp
	LD_LIBRARY_PATH=`pwd` ./prog-b one > test-b.temp
	cmp test.temp test-a.temp && echo -e "$(GREEN)SUCCESS$(RS)" || echo -e "$(RED)FAIL$(RS)"
	cmp test.temp test-b.temp && echo -e "$(GREEN)SUCCESS$(RS)" || echo -e "$(RED)FAIL$(RS)"

test2: prog prog-a prog-b
	./prog 1 2 3 > test.temp
	./prog-a 1 2 3 > test-a.temp
	LD_LIBRARY_PATH=`pwd` ./prog-b 1 2 3 > test-b.temp
	cmp test.temp test-a.temp && echo -e "$(GREEN)SUCCESS$(RS)" || echo -e "$(RED)FAIL$(RS)"
	cmp test.temp test-b.temp && echo -e "$(GREEN)SUCCESS$(RS)" || echo -e "$(RED)FAIL$(RS)"

