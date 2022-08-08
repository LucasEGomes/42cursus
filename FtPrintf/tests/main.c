/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:13:17 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/05 22:48:15 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

extern int	ft_printf(const char *format, ...);

#define RUN(args...) \
	printf("; %d", f(args)); \
	printf("\n"); \
	fflush(stdout)

int	main(int argc, char **argv)
{
	int	stdout_copy;
	int	custom;
	int	original;
	int	(*f)(const char *fmt, ...);
	int	iterations;

	if (argc == 3)
	{
		original = open(argv[1], O_CREAT | O_TRUNC | O_RDWR, 0644);
		custom = open(argv[2], O_CREAT | O_TRUNC | O_RDWR, 0644);
		stdout_copy = dup(STDOUT_FILENO);
		dup2(original, STDOUT_FILENO);
	}
	f = printf;
	iterations = 2;
	while (iterations)
	{
		// no conversions
		RUN("Complete normal text.");
		RUN("Followed by a new line.");
		RUN("");

		// c conversion specifier
		RUN("%c", 'A');
		RUN("%c", '~');
		RUN("%c", 304);
		RUN("Hello There%c", '!');
		RUN("General Kenobi%c%cHello There%c", '.', '\n', '!');

		// s conversion specifier
		RUN("%s", NULL);
		RUN("%s", "Hello There");
		RUN("%s%s%s%s", "Hello ", "There!\n", "General ", "Kenobi.\n");
		RUN("%s There!\n%s Kenobi.", "Marshmallow", "Duck");
		RUN("%s string shows the value of %s", "The following", NULL);
		RUN("This is a empty string: `%s`", "");
		RUN("%s", "");

		// p conversion specifier
		RUN("%p", NULL);
		RUN("%p", &original);
		RUN("There is another pointer: %p", &f);
		RUN("%p, %p, %p little pointers", NULL, &iterations, &stdout_copy);

		// d and i conversion specifier
		RUN("%d", -1);
		RUN("%d", 9);
		RUN("%d", 0);
		RUN("%d", 10);
		RUN("%d", 100);
		RUN("%d", 10000);
		RUN("%d", INT_MIN);
		RUN("%d", INT_MAX);
		RUN("%d", 4242);
		RUN("%d", -1023456789);
		RUN("%i", -1);
		RUN("%i", 9);
		RUN("%i", 0);
		RUN("%i", 10);
		RUN("%i", 100);
		RUN("%i", 10000);
		RUN("%i", INT_MIN);
		RUN("%i", INT_MAX);
		RUN("%i", 4242);
		RUN("%i", -1023456789);
		RUN("Hello %i, there is another conversion %d", 123, 9854);
		RUN("%d.%i%i%d%d%d%i", 3, 1, 4, 1, 5, 9, 2);

		// u conversion specifier
		RUN("%u", 0U);
		RUN("%u", 4294967295U);
		RUN("%u", 9U);
		RUN("%u", 10U);
		RUN("%u", 100U);
		RUN("%u", 1000U);
		RUN("%u", 100000U);
		RUN("%u", 4242U);
		RUN("Hello %u, there is another conversion %u", 123U, 9854U);
		RUN("%u.%u%u%u%u%u%u", 3U, 1U, 4U, 1U, 5U, 9U, 2U);

		// x conversion specifier
		RUN("%x", 0x0U);
		RUN("%x", 0xFFFFFFFFU);
		RUN("%x", 0x9U);
		RUN("%x", 0xAU);
		RUN("%x", 0x64U);
		RUN("%x", 0x3E8U);
		RUN("%x", 0x186A0U);
		RUN("%x", 0x1092U);
		RUN("Hello %x, there is another conversion %x", 0x7BU, 0x267EU);
		RUN("%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x", 0x0U, 0x1U, 0x2U, 0x3U, 0x4U, 0x5U, 0x6U, 0x7U, 0x8U, 0x9U, 0xAU, 0xBU, 0xCU, 0xDU, 0xEU, 0xFU);
		RUN("Three `%x` big `%x` numbers `%x`", 0xABCDEFU, 0x102345U, 0x6789U);

		// X conversion specifier
		RUN("%X", 0x0U);
		RUN("%X", 0xFFFFFFFFU);
		RUN("%X", 0x9U);
		RUN("%X", 0xAU);
		RUN("%X", 0x64U);
		RUN("%X", 0x3E8U);
		RUN("%X", 0x186A0U);
		RUN("%X", 0x1092U);
		RUN("Hello %X, there is another conversion %X", 0x7BU, 0x267EU);
		RUN("%X%X%X%X%X%X%X%X%X%X%X%X%X%X%X%X", 0x0U, 0x1U, 0x2U, 0x3U, 0x4U, 0x5U, 0x6U, 0x7U, 0x8U, 0x9U, 0xAU, 0xBU, 0xCU, 0xDU, 0xEU, 0xFU);
		RUN("Three `%X` big `%X` numbers `%X`", 0xABCDEFU, 0x102345U, 0x6789U);

		// % conversion specifier
		RUN("%%");
		RUN("%%%%");
		RUN("There is a percent sign %%");
		RUN("%% a percent sign was there");

		// Invalid specifiers
		RUN("% < represents an incomplete specifier. In that case a single percent sign");
		RUN("%R < represents an invalid specifier");
		RUN("It's hard to choose %) invalid specifiers: `%^`");

		// Multiple specifiers
		RUN("The %c character is the best, because the %s use this character " \
			"as its name.\nPointers, like %p or %p, can be hard to " \
			"understand, but are very useful.\nThere are several types, " \
			"like integers, to represent decimal numbers either positive (%d)" \
			"or negative (%i). Unsigned is possible too, so you can write " \
			"larger numbers as %u.\nIt's possible to write numbers as " \
			"hexadecimal (0%x%x), just prefix with '0x' and done. So to write %d" \
			" as hexadecimal, you write 0x%X or 0x%x. %c is 100%% fun!",
			'C', "ANSI C Language", NULL, &f, 123456, -987654, 2274017296U,
			0x1234567, 0x89ABCDEF, 42, 0x2A, 0x2A, 'C');

		if (argc == 3)
		{
			fflush(stdout);
			close(original);
			dup2(custom, STDOUT_FILENO);
		}
		f = ft_printf;
		iterations--;
	}
	if (argc == 3)
	{
		close(custom);
		fflush(stdout);
		dup2(stdout_copy, STDOUT_FILENO);
	}
	return (0);
}