#include "ex20.h"

int	g_fake = 0;

void	*__wrap_malloc(size_t size)
{
	if (g_fake)
		return (NULL);
	return (__real_malloc(size));
}

int	main(void)
{
	run("So she was considering in her own mind (as well as she could, ");
	g_fake = 1;
	run("for the hot day made her feel very sleepy and stupid), whether ");
	run("the pleasure of making a daisy-chain would be worth the trouble ");
	run("of getting up and picking the daisies, when suddenly a White ");
	g_fake = 0;
	run("Rabbit with pink eyes ran close by her.");
}
