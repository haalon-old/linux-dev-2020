/**
 * @file guess.c
 * Guess the number app
 */

#include <stdio.h>
#include <string.h>

#include <libintl.h>
#include <locale.h>
#include "roman.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#define _(STRING) gettext(STRING)


#define HELP _("\
'guess' program guesses your number in decimal or roman form\n\
\n\
Usage: guess [OPTIONS]\n\
\n\
\t--help\t\tprint this help\n\
\t--version\tprint version\n\
\t-r\t\tuse roman mode\n\
")
#endif

/**
 * Translate roman @p r to decimal
 *
 * @param r Roman number
 * @returns Decimal number
 */
int toDec(char * r) {
	for (int i = 0; i < roman_num; ++i)	{
		if(!strcmp(r, romans[i]))
			return i;
	}

	return -1;
}

/**
 * Translate decimal @p d to roman
 *
 * @param d Decimal number
 * @returns Roman number
 */ 
char * toRom(int i) {
	if(i < 0 && i > 100)
		return NULL;

	return romans[i];
}

int main(int argc, char const *argv[])
{
	// setlocale(LC_ALL, "ru_RU.UTF-8");
	setlocale (LC_ALL, "");
	bindtextdomain ("guess", ".");
	textdomain ("guess");
	char rom_mode=0;
	for (int i = 1; i < argc; ++i)
	{
		if(!strcmp(argv[i], "--version"))
			return !printf("0.0.0\n");

		if(!strcmp(argv[i], "--help"))
			return !printf("%s\n", HELP);

		if(!strcmp(argv[i], "-r"))
			rom_mode=1;
	}

	int l = 1, h = 100;
	char buf[8];
	if(!rom_mode)
		printf(_("Come up with a number between %d and %d\n"), l, h);
	else
		printf(_("Come up with a number between %s and %s\n"), toRom(l), toRom(h));
	printf(_("I ll try to guess it now\n\n"));

	while(1)
	{
		if(!rom_mode)
			printf(_("Is your number between %d and %d?\n"), l, (l+h)/2);
		else
			printf(_("Is your number between %s and %s?\n"), toRom(l), toRom((l+h)/2));
		printf(_("(answer 'yes' or 'no')\n"));

		scanf("%s", buf);

		if(!strcmp(buf, _("yes")))
			h=(l+h)/2;
		else if(!strcmp(buf, _("no")))
			l=(l+h)/2+1;
		else
			printf(_("Please answer correctly\n"));

		if(l == h)
			break;
	}
	if(!rom_mode)
		printf(_("Your number is %d!\n"), l);
	else
		printf(_("Your number is %s!\n"), toRom(l));


	/* code */
	return 0;
}