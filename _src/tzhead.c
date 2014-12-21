#include <stdlib.h>
#include <string.h>
#include <tzfile.h>

enum e_macro
{
	NEW,
	GET
};

struct tzhead	*new_tzhead(void)
{
	struct tzhead	*new;

	if (!(new = (struct tzhead*)malloc(sizeof(struct tzhead))))
		return (NULL);
	bzero((void*)(&new->tzh_magic), sizeof(char) * 4);
	bzero((void*)(&new->tzh_reserved), sizeof(char) * 16);
	bzero((void*)(&new->tzh_ttisgmtcnt), sizeof(char) * 4);
	bzero((void*)(&new->tzh_ttisstdcnt), sizeof(char) * 4);
	bzero((void*)(&new->tzh_leapcnt), sizeof(char) * 4);
	bzero((void*)(&new->tzh_timecnt), sizeof(char) * 4);
	bzero((void*)(&new->tzh_typecnt), sizeof(char) * 4);
	bzero((void*)(&new->tzh_charcnt), sizeof(char) * 4);
	return (new);
}

struct tzhead	*manage_tzhead(int macro)
{
	static struct tzhead	*current;

	if (macro == NEW)
		current = new_tzhead();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_tzhead: no decent macro\n", 31);
	return (NULL);
}
