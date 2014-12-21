#include <stdlib.h>
#include <string.h>
#include <disktab.h>

enum e_macro
{
	NEW,
	GET
};

struct disktab	*new_disktab(void)
{
	struct disktab	*new;

	if (!(new = (struct disktab*)malloc(sizeof(struct disktab))))
		return (NULL);
	new->d_name = NULL;
	new->d_type = NULL;
	new->d_secsize = 0;
	new->d_ntracks = 0;
	new->d_nsectors = 0;
	new->d_ncylinders = 0;
	new->d_rpm = 0;
	new->d_badsectforw = 0;
	new->d_sectoffset = 0;
	new->p_size = 0;
	new->p_bsize = 0;
	new->p_fsize = 0;
	return (new);
}

struct disktab	*manage_disktab(int macro)
{
	static struct disktab	*current;

	if (macro == NEW)
		current = new_disktab();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_disktab: no decent macro\n", 32);
	return (NULL);
}
