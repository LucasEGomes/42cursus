#include "ex17.h"

int	main(void)
{
	char string_0[9] = "Hello ";
	char string_1[7] = "Hello ";
	char string_2[8] = "Hello ";
	char string_3[9] = "Hello ";

	
	run("", "", 0);
	run("", "Hello There", -1);
	run("Hello There", "", 1);
	run("Hello ", "Hello There", -1);
	run("Hello There", "Hello ", 1);
	string_0[6] = -128;
	string_0[7] = -1;
	string_0[8] = '\0';;
	run(string_0, string_1, 1);
	run(string_1, string_0, -1);
	string_2[6] = -128;
	string_2[7] = '\0';
	run(string_0, string_2, 1);
	run(string_2, string_0, -1);
	string_3[6] = -128;
	string_3[7] = -1;
	string_3[8] = '\0';
	run(string_0, string_3, 0);
	run(string_3, string_0, 0);
	string_3[7] = -57;
	run(string_0, string_3, 1);
	run(string_3, string_0, -1);
}
