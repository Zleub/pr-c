#include <stdlib.h>
#include <string.h>
#include <cache.h>

enum e_macro
{
	NEW,
	GET
};

struct cache_attributes_s	*new_cache_attributes_s(void)
{
	struct cache_attributes_s	*new;

	if (!(new = (struct cache_attributes_s*)malloc(sizeof(struct cache_attributes_s))))
		return (NULL);
	new->version = 0;
	new->key_hash_cb = 0;
	new->key_is_equal_cb = 0;
	new->key_retain_cb = 0;
	new->key_release_cb = 0;
	new->value_release_cb = 0;
	new->value_make_nonpurgeable_cb = 0;
	new->value_make_purgeable_cb = 0;
	new->user_data = NULL;
	new->value_retain_cb = 0;
	return (new);
}

struct cache_attributes_s	*manage_cache_attributes_s(int macro)
{
	static struct cache_attributes_s	*current;

	if (macro == NEW)
		current = new_cache_attributes_s();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_cache_attributes_s: no decent macro\n", 43);
	return (NULL);
}
