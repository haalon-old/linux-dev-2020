/* COMMENT:: namegen 0.0:Пт 11 дек 2020 16:05:40 MSK */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "namegen.h"
#include "config.h"

#define MAXLEN 64
#define MANUAL "Namegen is used for generating stupid fantasy syle names\n\
\n\
Usage: namegen [OPTION] [PATTERN [SEED]]\n\
\n\
    --help		print this help, then exit\n\
    --version		print version number, then exit\n\
\n\
The namegen program creates a name generator based on an input\n\
pattern. The letters s, v, V, c, B, C, i, m, M, D, and d represent\n\
different types of random replacements. Everything else is emitted\n\
literally.\n\
\n\
 s  generic syllable\n\
 v  vowel\n\
 V  vowel or vowel combination\n\
 c  consonant\n\
 B  consonant or consonant combination suitable for beginning a word\n\
 C  consonant or consonant combination suitable anywhere in a word\n\
 i  insult\n\
 m  mushy name\n\
 M  mushy name ending\n\
 D  consonant suited for a stupid person's name\n\
 d  syllable suited for a stupid person's name (begins with a vowel)\n\
\n\
All characters between parenthesis () are emitted literally. For\n\
example, the pattern 's(dim)', emits a random generic syllable\n\
followed by 'dim'.\n\
\n\
Characters between angle brackets <> emit patterns from the table\n\
above. Imagine the entire pattern is wrapped in one of these.\n\
\n\
In both types of groupings, a vertical bar | denotes a random choice.\n\
Empty groups are allowed. For example, '(foo|bar)' emits either 'foo'\n\
or 'bar'. The pattern '<c|v|>' emits a constant, vowel, or nothing at\n\
all.\n\
\n\
An exclamation point ! means to capitalize the component that follows\n\
it. For example, '!(foo)' will emit 'Foo' and 'v!s' will emit a\n\
lowercase vowel followed by a capitalized syllable, like 'eRod'.\n\
"

char name[MAXLEN];
int main(int argc, char **argv) {
	unsigned long seed;
	char *pattern = "!sV'i";
	int i;

	for(i=1; i<argc; i++)
		if(!strcmp(argv[i], "--help"))
			return !printf("%s\n", MANUAL);
		else if(!strcmp(argv[i], "--version"))
			return !printf("namegen %s\n", VERSION);
		else {
			pattern = argv[i];
			seed = argc>i+1? atol(argv[i+1]) : time(NULL);
			break;
		}
	srandom(seed);
	namegen(name, sizeof(name), pattern, &seed);
	puts(name);
	return 0;
}

