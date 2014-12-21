#include <stdlib.h>
#include <string.h>
#include <utmpx.h>

enum e_macro
{
	NEW,
	GET
};

struct utmpx	*new_utmpx(void)
{
	struct utmpx	*new;

	if (!(new = (struct utmpx*)malloc(sizeof(struct utmpx))))
		return (NULL);
	bzero((void*)(&new->ut_user), sizeof(char) * _UTX_USERSIZE);
	bzero((void*)(&new->ut_id), sizeof(char) * _UTX_IDSIZE);
	bzero((void*)(&new->ut_line), sizeof(char) * _UTX_LINESIZE);
	new->ut_pid = 0;
	new->ut_type = 0;
	bzero((void*)(&new->ut_tv), sizeof(struct timeval));
	bzero((void*)(&new->ut_host), sizeof(char) * _UTX_HOSTSIZE);
	bzero((void*)(&new->ut_pad), sizeof(__uint32_t) * 16);
	return (new);
}

struct utmpx	*manage_utmpx(int macro)
{
	static struct utmpx	*current;

	if (macro == NEW)
		current = new_utmpx();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_utmpx: no decent macro\n", 30);
	return (NULL);
}
