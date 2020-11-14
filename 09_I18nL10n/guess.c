#include <stdio.h>
#include <string.h>

#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)

int main(int argc, char const *argv[])
{
	 // setlocale(LC_ALL, "ru_RU.UTF-8");
	setlocale (LC_ALL, "");
	bindtextdomain ("guess", ".");
	textdomain ("guess");

	int l = 1, h = 100;
	char buf[8];
	printf(_("Come up with a number between 1 and 100\n"));
	printf(_("I ll try to guess it now\n\n"));

	while(1)
	{
		printf(_("Is your number between %d and %d?\n"), l, (l+h)/2);
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
	printf(_("Your number is %d!\n"), l);


	/* code */
	return 0;
}