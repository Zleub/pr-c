#include <stdlib.h>
#include <string.h>
#include <curses.h>

enum e_macro
{
	NEW,
	GET
};

struct pdat	*new_pdat(void)
{
	struct pdat	*new;

	if (!(new = (struct pdat*)malloc(sizeof(struct pdat))))
		return (NULL);
	new->_pad_y,      _pad_x = 0;
	new->_pad_top,    _pad_left = 0;
	new->_pad_bottom, _pad_right = 0;
	return (new);
}

struct pdat	*manage_pdat(int macro)
{
	static struct pdat	*current;

	if (macro == NEW)
		current = new_pdat();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_pdat: no decent macro\n", 29);
	return (NULL);
}
