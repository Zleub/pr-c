#include <stdlib.h>
#include <string.h>
#include <unwind.h>

enum e_macro
{
	NEW,
	GET
};

struct _Unwind_Exception	*new__Unwind_Exception(void)
{
	struct _Unwind_Exception	*new;

	if (!(new = (struct _Unwind_Exception*)malloc(sizeof(struct _Unwind_Exception))))
		return (NULL);
	new->exception_class = 0;
	new->exception_cleanup = NULL;
	new->private_1 = 0;
	new->private_2 = 0;
	bzero((void*)(&new->reserved), sizeof(uint32_t) * 3);
	return (new);
}

struct _Unwind_Exception	*manage__Unwind_Exception(int macro)
{
	static struct _Unwind_Exception	*current;

	if (macro == NEW)
		current = new__Unwind_Exception();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage__Unwind_Exception: no decent macro\n", 42);
	return (NULL);
}
