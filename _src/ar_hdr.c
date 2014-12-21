#include <stdlib.h>
#include <string.h>
#include <ar.h>

enum e_macro
{
	NEW,
	GET
};

struct ar_hdr	*new_ar_hdr(void)
{
	struct ar_hdr	*new;

	if (!(new = (struct ar_hdr*)malloc(sizeof(struct ar_hdr))))
		return (NULL);
	bzero((void*)(&new->ar_name), sizeof(char) * 16);
	bzero((void*)(&new->ar_date), sizeof(char) * 12);
	bzero((void*)(&new->ar_uid), sizeof(char) * 6);
	bzero((void*)(&new->ar_gid), sizeof(char) * 6);
	bzero((void*)(&new->ar_mode), sizeof(char) * 8);
	bzero((void*)(&new->ar_size), sizeof(char) * 10);
	bzero((void*)(&new->ar_fmag), sizeof(char) * 2);
	return (new);
}

struct ar_hdr	*manage_ar_hdr(int macro)
{
	static struct ar_hdr	*current;

	if (macro == NEW)
		current = new_ar_hdr();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_ar_hdr: no decent macro\n", 31);
	return (NULL);
}
