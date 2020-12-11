#include "namegen.h"

#define SZ 40
char name[SZ];
unsigned long seed = 100500;

#suite Fixed
#test tnamegen
	namegen(name, sizeof(name), "!sV'i", &seed);
	ck_assert_str_eq(name, "Aleei'bum");

#test tnamegen2
	namegen(name, sizeof(name), "!<B|D>Vs (from|of) !<B|D>Vs", &seed);
	ck_assert_str_eq(name, "Featur from Dauech");
