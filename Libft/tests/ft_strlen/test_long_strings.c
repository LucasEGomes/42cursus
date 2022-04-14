#include "tests.h"

int	main(void)
{
	char	*inputs[] = {
		"Alice was beginning to get very tired of sitting by her sister on the "
		"bank, and of having nothing to do:  once or twice she had peeped into "
		"the book her sister was reading, but it had no pictures or "
		"conversations in it, `and what is the use of a book,'thought Alice "
		"`without pictures or conversation?'",
		"There was nothing so VERY remarkable in that; nor did Alice "
		"think it so VERY much out of the way to hear the Rabbit say to "
		"itself, `Oh dear!  Oh dear!  I shall be late!'  (when she thought "
		"it over afterwards, it occurred to her that she ought to have "
		"wondered at this, but at the time it all seemed quite natural); "
		"but when the Rabbit actually TOOK A WATCH OUT OF ITS WAISTCOAT-"
		"POCKET, and looked at it, and then hurried on, Alice started to "
		"her feet, for it flashed across her mind that she had never "
		"before seen a rabbit with either a waistcoat-pocket, or a watch to "
		"take out of it, and burning with curiosity, she ran across the "
		"field after it, and fortunately was just in time to see it pop "
		"down a large rabbit-hole under the hedge.",
		0
	};
	size_t	results[] = {301, 736};
	int		index;

	index = 0;
	while (inputs[index] != 0)
	{
		if (ft_strlen(inputs[index]) != results[index])
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
