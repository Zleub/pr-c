#include <stdlib.h>
#include <string.h>
#include <fts.h>

enum e_macro
{
	NEW,
	GET
};

struct _ftsent	*new__ftsent(void)
{
	struct _ftsent	*new;

	if (!(new = (struct _ftsent*)malloc(sizeof(struct _ftsent))))
		return (NULL);
	new->fts_cycle = NULL;
	new->fts_parent = NULL;
	new->fts_link = NULL;
	new->fts_number = 0;
	new->fts_pointer = NULL;
	new->fts_accpath = NULL;
	new->fts_path = NULL;
	new->fts_errno = 0;
	new->fts_symfd = 0;
	new->fts_pathlen = 0;
	new->fts_namelen = 0;
	new->fts_ino = 0;
	new->fts_dev = 0;
	new->fts_nlink = 0;
	new->fts_level = 0;
	new->fts_info = 0;
	new->fts_flags = 0;
	new->fts_instr = 0;
	new->fts_statp = NULL;
	bzero((void*)(&new->fts_name), sizeof(char) * 1);
	return (new);
}

struct _ftsent	*manage__ftsent(int macro)
{
	static struct _ftsent	*current;

	if (macro == NEW)
		current = new__ftsent();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage__ftsent: no decent macro\n", 32);
	return (NULL);
}
