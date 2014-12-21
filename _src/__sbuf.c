#include <stdlib.h>
#include <string.h>
#include <stdio.h>

enum e_macro
{
	NEW,
	GET
};

struct __sbuf	*new___sbuf(void)
{
	struct __sbuf	*new;

	if (!(new = (struct __sbuf*)malloc(sizeof(struct __sbuf))))
		return (NULL);
	new->_base = NULL;
	new->_size = 0;
	return (new);
}

struct __sbuf	*manage___sbuf(int macro)
{
	static struct __sbuf	*current;

	if (macro == NEW)
		current = new___sbuf();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage___sbuf: no decent macro\n", 31);
	return (NULL);
}
