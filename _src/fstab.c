#include <stdlib.h>
#include <string.h>
#include <fstab.h>

enum e_macro
{
	NEW,
	GET
};

struct fstab	*new_fstab(void)
{
	struct fstab	*new;

	if (!(new = (struct fstab*)malloc(sizeof(struct fstab))))
		return (NULL);
	new->fs_spec = NULL;
	new->fs_file = NULL;
	new->fs_vfstype = NULL;
	new->fs_mntops = NULL;
	new->fs_type = NULL;
	new->fs_freq = 0;
	new->fs_passno = 0;
	return (new);
}

struct fstab	*manage_fstab(int macro)
{
	static struct fstab	*current;

	if (macro == NEW)
		current = new_fstab();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_fstab: no decent macro\n", 30);
	return (NULL);
}
