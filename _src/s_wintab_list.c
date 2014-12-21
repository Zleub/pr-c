#include <stdlib.h>
#include <string.h>
#include <curse.h>

enum e_macro
{
	NEW,
	GET
};

struct s_wintab_list	*new_s_wintab_list(void)
{
	struct s_wintab_list	*new;

	if (!(new = (struct s_wintab_list*)malloc(sizeof(struct s_wintab_list))))
		return (NULL);
	new->array = NULL;
	new->next = NULL;
	return (new);
}

struct s_wintab_list	*manage_s_wintab_list(int macro)
{
	static struct s_wintab_list	*current;

	if (macro == NEW)
		current = new_s_wintab_list();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_s_wintab_list: no decent macro\n", 38);
	return (NULL);
}
