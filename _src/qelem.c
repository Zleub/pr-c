#include <stdlib.h>
#include <string.h>
#include <libc.h>

enum e_macro
{
	NEW,
	GET
};

struct qelem	*new_qelem(void)
{
	struct qelem	*new;

	if (!(new = (struct qelem*)malloc(sizeof(struct qelem))))
		return (NULL);
	new->q_forw = NULL;
	new->q_back = NULL;
	new->q_data = NULL;
	return (new);
}

struct qelem	*manage_qelem(int macro)
{
	static struct qelem	*current;

	if (macro == NEW)
		current = new_qelem();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_qelem: no decent macro\n", 30);
	return (NULL);
}
