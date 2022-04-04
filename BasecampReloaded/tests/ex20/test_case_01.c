#include "ex20.h"

void	*__wrap_malloc(size_t size)
{
	return (__real_malloc(size));
}

int	main(void)
{
	run("Hello There \0General Kenobi!");
	run("vel quam elementum pulvinar etiam non quam lacus suspendisse faucibus "
		"interdum posuere lorem ipsum dolor sit amet consectetur adipiscing");
	run("");
	run("Alice was beginning to get very tired of sitting by her sister "
		"on the bank, and of having nothing to do:  once or twice she had "
		"peeped into the book her sister was reading, but it had no "
		"pictures or conversations in it, `and what is the use of a book,` "
		"thought Alice `without pictures or conversation?`");
}
