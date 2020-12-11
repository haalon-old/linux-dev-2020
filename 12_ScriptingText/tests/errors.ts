#include "namegen.h"

#define SZ 40
char name[SZ];
unsigned long seed = 100500;

#suite Errors
#test unclosed1
	int r;
        r = namegen(name, sizeof(name), "(a", &seed);
	ck_assert_int_eq(r, NAMEGEN_INVALID);

#test unclosed2
	int r;
        r = namegen(name, sizeof(name), "a>", &seed);
	ck_assert_int_eq(r, NAMEGEN_INVALID);

