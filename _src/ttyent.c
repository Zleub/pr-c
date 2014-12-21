#include <stdlib.h>
#include <string.h>
#include <ttyent.h>

enum e_macro
{
	NEW,
	GET
};

struct ttyent	*new_ttyent(void)
{
	struct ttyent	*new;

	if (!(new = (struct ttyent*)malloc(sizeof(struct ttyent))))
		return (NULL);
	new->ty_name = NULL;
	new->ty_getty = NULL;
	new->ty_type = NULL;
	new->ty_status = 0;
	new->ty_window = NULL;
	new->ty_onerror = NULL;
	new->ty_onoption = NULL;
	new->ty_comment = NULL;
	return (new);
}

struct ttyent	*manage_ttyent(int macro)
{
	static struct ttyent	*current;

	if (macro == NEW)
		current = new_ttyent();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ttyent: no decent macro\n", 31);
	return (NULL);
}
