#include "main.h"
#include <limits.h>

int main(void)
{
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
	_printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	_printf("%d\n", -1024);
	_printf("%d\n", 0);
	return (0);
}
