#include <stdlib.h>
#include <string.h>
#include <dns_sd.h>

enum e_macro
{
	NEW,
	GET
};

struct CompileTimeAssertionChecks_DNS_SD	*new_CompileTimeAssertionChecks_DNS_SD(void)
{
	struct CompileTimeAssertionChecks_DNS_SD	*new;

	if (!(new = (struct CompileTimeAssertionChecks_DNS_SD*)malloc(sizeof(struct CompileTimeAssertionChecks_DNS_SD))))
		return (NULL);
	bzero((void*)(&new->assert0), sizeof(char) * (sizeof(union _TXTRecordRef_t) == 16) ? 1 : -1);
	return (new);
}

struct CompileTimeAssertionChecks_DNS_SD	*manage_CompileTimeAssertionChecks_DNS_SD(int macro)
{
	static struct CompileTimeAssertionChecks_DNS_SD	*current;

	if (macro == NEW)
		current = new_CompileTimeAssertionChecks_DNS_SD();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_CompileTimeAssertionChecks_DNS_SD: no decent macro\n", 58);
	return (NULL);
}
