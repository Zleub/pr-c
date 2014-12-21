#include <stdlib.h>
#include <string.h>
#include <utmpx.h>

enum e_macro
{
	NEW,
	GET
};

struct lastlogx	*new_lastlogx(void)
{
	struct lastlogx	*new;

	if (!(new = (struct lastlogx*)malloc(sizeof(struct lastlogx))))
		return (NULL);
	bzero((void*)(&new->ll_tv), sizeof(struct timeval));
	bzero((void*)(&new->ll_line), sizeof(char) * _UTX_LINESIZE);
	bzero((void*)(&new->ll_host), sizeof(char) * _UTX_HOSTSIZE);
	return (new);
}

struct lastlogx	*manage_lastlogx(int macro)
{
	static struct lastlogx	*current;

	if (macro == NEW)
		current = new_lastlogx();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_lastlogx: no decent macro\n", 33);
	return (NULL);
}
