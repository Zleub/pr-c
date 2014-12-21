#include <stdlib.h>
#include <string.h>
#include <tic.h>

enum e_macro
{
	NEW,
	GET
};

struct tinfo_fkeys	*new_tinfo_fkeys(void)
{
	struct tinfo_fkeys	*new;

	if (!(new = (struct tinfo_fkeys*)malloc(sizeof(struct tinfo_fkeys))))
		return (NULL);
	new->offset = 0;
	new->code = 0;
	return (new);
}

struct tinfo_fkeys	*manage_tinfo_fkeys(int macro)
{
	static struct tinfo_fkeys	*current;

	if (macro == NEW)
		current = new_tinfo_fkeys();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_tinfo_fkeys: no decent macro\n", 36);
	return (NULL);
}
