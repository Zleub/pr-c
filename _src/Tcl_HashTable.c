#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_HashTable	*new_Tcl_HashTable(void)
{
	struct Tcl_HashTable	*new;

	if (!(new = (struct Tcl_HashTable*)malloc(sizeof(struct Tcl_HashTable))))
		return (NULL);
	new->*buckets = NULL;
	bzero((void*)(&new->staticBuckets), sizeof(Tcl_HashEntry*) * TCL_SMALL_HASH_TABLE);
	new->numBuckets = 0;
	new->numEntries = 0;
	new->rebuildSize = 0;
	new->downShift = 0;
	new->mask = 0;
	new->keyType = 0;
	new->key)) = NULL;
	new->key, int *newPtr)) = NULL;
	new->typePtr = NULL;
	return (new);
}

struct Tcl_HashTable	*manage_Tcl_HashTable(int macro)
{
	static struct Tcl_HashTable	*current;

	if (macro == NEW)
		current = new_Tcl_HashTable();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_HashTable: no decent macro\n", 38);
	return (NULL);
}
